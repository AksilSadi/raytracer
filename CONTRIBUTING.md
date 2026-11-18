# Contributing

## Set up the development environment

The project uses the checked-in Dev Container to provide the same Ubuntu
toolchain to contributors.

1. Install Docker Desktop (or Docker Engine) and a Dev Container-compatible
   editor.
2. In VS Code, install the Dev Containers extension, open the repository, and
   run **Dev Containers: Reopen in Container** from the Command Palette.
3. Use the editor's terminal in the container for project commands.

The first container build and CMake configuration need network access to
download the system packages and Catch2.

## Build, run, and test

Run these commands from the repository root in the container:

```sh
make build
make run
make test
make clean
```

`make test` builds the project and runs the Catch2 tests through CTest.

## Test-driven development

Use the red/green/refactor cycle:

1. **Red:** write a test for the intended behavior and run `make test`, checking
   that it fails for the expected reason.
2. **Green:** make the smallest implementation that passes, then run
   `make test`.
3. **Refactor:** improve the implementation without changing behavior, then
   run `make test` again.

## Architecture decision records

Read the relevant records in `docs/adr/` before changing the build, tools, or
test setup. Do not go against an accepted ADR. To change a decision, write a
new ADR with status `Proposed` and ask the project owner. Contributors must
not set an ADR to `Accepted`.

## Submit a change

Use the GitHub pull request template to describe the change and the checks you
ran. The pull request workflow builds and tests the project in the Dev
Container environment; see `.github/workflows/ci.yml` and
`docs/adr/0005-github-actions-ci.md`.
