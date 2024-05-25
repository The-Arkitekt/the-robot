#!/bin/bash

# Push the source directory from the host to the development environment container
# WARNING: Replaces all contents of current source directory in container

podman cp $PWD/../source/ robot-dev:/home/development-user/

# Push the design directory from the host to the development environment container
# WARNING: Replaces all contaents of current designe directory in container

podman cp $PWD/../design/ robot-dev:/home/development-user/
