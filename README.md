# Raytracer

A student C++ project, bootstrapped with a small Hello World app, a
cross-platform CMake build, and Catch2 tests.

## Requirements

- CMake 3.20 or newer
- A C++17 compiler
- Ninja
- `make`
- Git and an internet connection the first time CMake configures the project
  (Catch2 is downloaded and pinned by CMake)

Install a compiler, Ninja, and `make` for your operating system:

- **Windows:** Visual Studio 2022 with the *Desktop development with C++*
  workload, plus CMake and Ninja. Run the commands below from a Visual Studio
  Developer PowerShell so the MSVC compiler is on `PATH`. GNU Make is included
  in the Dev Container; use it there, or install GNU Make for a native build.
- **macOS:** Xcode Command Line Tools, CMake, and Ninja (`make` is included).
- **Ubuntu/Debian:** `sudo apt install build-essential cmake ninja-build git`.

The same CMake presets and commands are used on all three platforms.

## Build, test, and run

From the repository root, use GNU Make:

```text
make build  # configure and compile
make run    # build, then run
make test   # build, then run the tests
make clean  # delete the build folder
```

The underlying CMake/CTest commands are also available directly:

```sh
cmake --preset default
cmake --build --preset default
ctest --preset default
./build/raytracer
```

In PowerShell, run the last command as `.\build\raytracer.exe`.

The `run` target uses CMake to run the executable across platforms. CTest
reports a non-zero exit status if a test fails. To run the test executable
directly and see Catch2's output:

```sh
./build/raytracer_tests
```

On Windows, use `.\build\raytracer_tests.exe`.

## Development container

The `.devcontainer` directory provides a reproducible Ubuntu toolchain.

- **VS Code:** install Docker and the Dev Containers extension, open this
  repository, then run **Dev Containers: Reopen in Container** from the
  Command Palette.
- **Zed:** open this repository and use the same CMake commands above with
  the local toolchain. The checked-in Makefile and CMake presets are
  editor-independent; the Dev Container can also be used with any client that
  supports the Development Containers specification.

Once inside the container, use the Make shortcuts above. The image includes
GNU Make, CMake, Ninja, Git, and the GNU C++ compiler.

## Test-driven development

Catch2 is the unit testing framework; CTest discovers and runs the test
executable. The existing greeting test is a minimal example:

1. **Red:** write a test for the behavior you want, then run `make test` and
   confirm it fails for the expected reason.
2. **Green:** implement only enough code to make the test pass, then run
   `make test` again.
3. **Refactor:** improve the implementation without changing behavior, and run
   `make test` again.

Add test cases in `tests/` and production code under `include/` and `src/`.
The first configure downloads Catch2, so an internet connection is required
unless the dependency is already available in CMake's build cache.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for the Dev Container setup, Make
commands, TDD workflow, and ADR guidance. GitHub issue and pull request
templates are in `.github/`; pull requests are checked by the
[CI workflow](.github/workflows/ci.yml), which uses the Dev Container image.
The CI decision is recorded in
[ADR 0005](docs/adr/0005-github-actions-ci.md).
