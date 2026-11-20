# 0007: Represent Colour as a distinct type

## Context

`Vector` and `Colour` each contain three numeric components, but they represent
different concepts. A vector represents a position or direction and supports
vector operations; a colour represents red, green and blue components. A
sphere has a colour, and a future image will store a colour for each pixel.

## Decision

Represent `Colour` as its own value class with `r`, `g` and `b` components.
Do not represent it as a `Vector`.

## Status

Accepted

## Consequences

The type system keeps geometry and colour values distinct, and colour-specific
behavior can be added without giving colours unrelated vector operations.
`Sphere` can hold a `Colour`, `trace` can return one, and `Image` can store them
when it is implemented. Colour range validation and clamping are not decided;
values above 1 may be needed for lighting.

The alternative was to reuse `Vector` because both types have three
components. That would make their meanings interchangeable in code and allow
operations that do not make sense for colour, so it was rejected.
