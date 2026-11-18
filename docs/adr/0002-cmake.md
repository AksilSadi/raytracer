# 0002: Use CMake and CTest

## Context

The project needs to manage its C++ build across different environments and
run automated tests. An alternative is to maintain environment-specific build
commands and test-running instructions.

## Decision

Use CMake to define and configure the build, with checked-in presets, and use
CTest to register and run the test executable. This manages the C++ build
across environments and integrates automated test execution.

## Status

Proposed

## Consequences

CMake and CTest provide a shared build and test workflow. Developers need
CMake 3.20 or newer and Ninja for the supplied preset; the initial
configuration needs an internet connection to fetch Catch2.
