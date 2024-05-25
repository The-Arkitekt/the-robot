#!/bin/bash

# Pull the source directory from the development environment container
# WARNING: Replaces all contents of current source directory

podman cp robot-dev:/home/development-user/source/ $PWD/../

# Pull the design directory from the development environment container
# WARNING: Replaces all contents of current source directory

podman cp robot-dev:/home/development-user/design/ $PWD/../
