# 0001: Use a development container

## Context

Developers could configure their machines independently, which can lead to
differences between environments. The alternative is to rely only on each
developer's local toolchain.

## Decision

Provide a Dev Container based on Ubuntu 24.04 with the C++ build tools, CMake,
Git, and Ninja, so everyone can use the same development environment and avoid
configuration differences between machines.

## Status

Proposed

## Consequences

The container provides a consistent toolchain. Using it requires Docker and a
client that supports Development Containers; the configured environment is
Ubuntu-based.
