#!/bin/bash
set -e

# Build and run the container for the SF3000 toolchain dev environment using podman
IMAGE_NAME=sf3000-toolchain:latest
CONTAINER_NAME=sf3000-toolchain-dev
WORKSPACE_DIR=$(pwd)

# Build the image
podman build -t $IMAGE_NAME .

# Remove any previous container with the same name
podman rm -f $CONTAINER_NAME 2>/dev/null || true

# Run the container interactively, mounting the current workspace
podman run --name $CONTAINER_NAME -it --rm \
  -v "$WORKSPACE_DIR:/workspace" \
  $IMAGE_NAME
