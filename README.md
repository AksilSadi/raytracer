# Raytracer

A student C++ project, bootstrapped with a small Hello World app, a
cross-platform CMake build, and Catch2 tests.

## Requirements

- CMake 3.20 or newer
- A C++17 compiler
- Ninja
- Git and an internet connection the first time CMake configures the project
  (Catch2 is downloaded and pinned by CMake)

Install a compiler and Ninja for your operating system:

- **Windows:** Visual Studio 2022 with the *Desktop development with C++*
  workload, plus CMake and Ninja. Run the commands below from a Visual Studio
  Developer PowerShell so the MSVC compiler is on `PATH`.
- **macOS:** Xcode Command Line Tools, CMake, and Ninja.
- **Ubuntu/Debian:** `sudo apt install build-essential cmake ninja-build git`

The same CMake presets and commands are used on all three platforms.

## Configure, build, test, and run

Run these commands from the repository root:

```sh
cmake --preset default
cmake --build --preset default
ctest --preset default
```

Run the demo:

```sh
./build/raytracer
```

On Windows, run `.\build\raytracer.exe` in PowerShell instead. The program
prints `Hello, World!`.

CTest reports a non-zero exit status if a test fails. To run the test
executable directly and see Catch2's output:

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
  the local C++ toolchain. The checked-in CMake presets are editor-independent;
  the Dev Container can also be used with any client that supports the
  Development Containers specification.

Once inside the container, configure, build, test, and run using the commands
in the previous section. The image includes CMake, Ninja, Git, and the GNU C++
compiler.

## Test-driven development

Catch2 is the unit testing framework; CTest discovers and runs the test
executable. The existing greeting test is a minimal example:

1. **Red:** write a test for the behavior you want, then run
   `ctest --preset default` and confirm it fails for the expected reason.
2. **Green:** implement only enough code to make the test pass, then run
   `cmake --build --preset default` and `ctest --preset default`.
3. **Refactor:** improve the implementation without changing behavior, and run
   the tests again.

Add test cases in `tests/` and production code under `include/` and `src/`.
The first configure downloads Catch2, so an internet connection is required
unless the dependency is already available in CMake's build cache.
