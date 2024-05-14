#!/bin/bash

# Copy the container file to the main directory so it has access to source code
cp ../dev-environment/Containerfile ../

# Build container using Containerfile
podman build -f ../Containerfile -t robot-dev-env:latest

# Remove the copied Containerfile
rm ../Containerfile
