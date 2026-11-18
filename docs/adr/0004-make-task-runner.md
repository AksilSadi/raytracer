# 0004: Use GNU Make for project shortcuts

## Context

Remembering the CMake and CTest commands for common tasks is inconvenient.
Running those commands manually is the alternative. GNU Make is available in
the Dev Container through its build tools.

## Decision

Use a Makefile to expose `clean`, `build`, `run`, and `test` shortcuts while
keeping CMake and CTest responsible for building and testing.

## Status

Proposed

## Consequences

The shortcuts make common project commands easier to remember. GNU Make is
required to use them; it is included in the Dev Container.
