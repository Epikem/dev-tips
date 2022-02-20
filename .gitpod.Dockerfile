FROM gitpod/workspace-full

# Install custom tools, runtime, etc.
RUN sudo apt-get update \
    && sudo apt-get install -y \
    git-secret

# Apply user-specific settings
# ENV ...

RUN gpg --import ./public.gpg
