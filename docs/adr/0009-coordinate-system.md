# 0009: Use a forward-z coordinate system and top-left image coordinates

## Context

The camera and the image count positions in different ways. World coordinates
are measured from the centre of the screen, with x to the right and y up.
Image pixels are counted from the top left: columns go right and rows go down.
The y direction therefore has to be inverted when mapping a pixel to the world.

## Decision

Use x to the right, y up and z forward for world coordinates. Count image
pixels from the top left, with columns increasing to the right and rows
increasing downwards. Camera rays travel forward along +z through the centre of
each pixel.

## Status

Accepted

## Consequences

The camera maps pixel centres onto the screen using the image's top-left
coordinates and reverses the row direction for world y. Tests use an odd,
non-square image so that width, height and vertical orientation errors are
visible.

The alternative was to look along -z, as in *Ray Tracing in One Weekend*. The
project uses +z forward instead.
