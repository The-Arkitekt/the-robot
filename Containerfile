# Set base image
FROM archlinux:latest 

# Update pacman
RUN pacman -Syu --noconfirm

# Create user space 
RUN useradd -m env-user

USER env-user

# install environment dependencies as ROOT
RUN pacman -S --noconfirm git neovim

# create a user space 
