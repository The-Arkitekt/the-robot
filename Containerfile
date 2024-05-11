# Set base image
FROM archlinux:latest 

# Update pacman
RUN pacman -Syu --noconfirm

# Get sudo and git
RUN pacman -S --noconfirm sudo git

# Create user space 
RUN useradd -m env-user

# Add user to sudoers
RUN echo env-user ALL=(ALL:ALL) ALL >> /etc/sudoers

# Do subsequent commands as the env-user
USER env-user

# Get paru so we can use the latest community packages
RUN sudo pacman -S --noconfirm --needed base-devel
RUN git clone https://aur.archlinux.org/paru.git && cd paru && makepkg -si

# Use paru to get neovim 
RUN paru -S --noconfirm neovim-git

# Add the nvim config directory to container
ADD neovim-config/* /home/env-user/.config/nvim/

# Start nvim 
RUN nvim

