# 0006: Organize code by concept

## Context

Keeping every source file in one flat `src/` directory makes related code
harder to find as the project grows. Tests should be discoverable from the
concept they verify. A flat layout is simpler while there are very few files,
but does not group implementations and tests by domain.

## Decision

Starting with new domain classes, organize implementation files under
`src/<concept>/` and mirror that structure under `tests/<concept>/`. Include
project headers using paths relative to `src/`, such as
`#include "math/vector.h"`. Keep the existing `main.cpp` and greeting
bootstrap files where they are; do not create empty concept directories.

## Status

Accepted

## Consequences

Related implementations and tests are easier to locate, and include paths
show which concept a header belongs to. The directory tree is deeper, and
adding a source or test file also requires updating the appropriate CMake
source list. The `src/` include root must be configured for targets that use
these headers. Creating a folder for every tiny or speculative concept would
add needless navigation, so a concept folder is created with its first class.

## Deferred decisions

- **Namespaces:** Keep `Vector` in the global namespace for now. Introduce a
  project namespace when names collide or when partner studios need to embed
  the code alongside their own.
- **One library per folder:** Keep one core library for now. Split concepts
  into separate targets when the build needs enforceable dependency
  boundaries or independently built targets measurably reduce build times;
  more folders alone do not justify more libraries.
- **Separate public and private header trees:** Keep new concept headers with
  their implementation under `src/` for now. Organize public headers under
  `include/` separately from private implementation headers when the project
  is shipped as a library and needs a defined public API.
