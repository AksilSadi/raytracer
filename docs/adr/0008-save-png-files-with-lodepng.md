# 0008: Save PNG files with LodePNG

## Context

The client opens our rendered images in ordinary viewers, so the project needs
to save PNG files. PNG is compressed and includes checksums, which keeps the
files small and detects corrupted blocks. Writing a PNG encoder ourselves would
take too much time and create too many opportunities for bugs.

## Decision

Use LodePNG, from https://github.com/lvandeve/lodepng, as the PNG implementation.
Download it with CMake `FetchContent`, as Catch2 is downloaded, and pin it to
commit `7b2893e35891c0c85bee5595caafaf3c2044b409`, because LodePNG has no
releases.

Only `src/output/` will use LodePNG, behind the project's own `ImageSaver`
interface. This keeps the PNG library and format implementation behind one
class of ours.

## Status

Accepted

## Consequences

PNG output will use a maintained library with no external installation and
will fit the CMake build. LodePNG provides a C++ interface and can work with
`std::vector` data. The pinned commit makes builds reproducible; upgrading
requires deliberately changing the commit in CMake.

LodePNG is slower than some alternatives at saving. It also introduces an
additional adapter layer: one interface and one implementation are present now,
instead of using the library directly throughout the project. That abstraction
allows a later saver implementation or format to replace or supplement PNG
without changing the rest of the application.

The alternatives were libpng, stb_image_write and PPM. libpng is the reference
PNG library, but its C API requires many calls and is not in the dev container.
stb_image_write is a public-domain, single-header library, but its C API uses
raw pointers and produces larger PNG files. LodePNG is one `.cpp` and one `.h`,
uses the zlib licence, has no dependencies, and exposes a C++ interface with
`std::vector`; it is slower than the other PNG libraries at saving. PPM needs
no library and can be written by hand, but most viewers cannot open it and the
files are much larger.
