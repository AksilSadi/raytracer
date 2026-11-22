# 0010: A shape has a material

## Context

A sphere and a plane have different intersection maths, but both can use the
same diffuse shading law. The geometry determines where the ray hits and
which way the surface faces. The material determines the colour under the
light. Geometry and shading need to vary independently.

## Decision

Use composition. Each concrete shape holds a `Material` value and includes
it in the `Hit` it returns. The `Shape` interface defines intersection, and
`trace` delegates shading to the hit's material.

## Status

Proposed

## Consequences

The sphere and the plane can reuse the same shading code, and a new shape can
use an existing material. The alternative was to express the material through
shape subclasses such as `MatteSphere` and `MirrorSphere`. Each new shape
would need one subclass per material, and each new material would need one
per shape.
