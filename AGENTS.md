# Project instructions

From the project root:

- Configure: `cmake --preset default`
- Build: `cmake --build --preset default`
- Run: `./build/raytracer` (`.\build\raytracer.exe` on Windows)
- Test: `ctest --preset default`

Architecture decisions are in `docs/adr/`. Read them before changing the
build, tools, or test setup. Never go against an accepted ADR. To change a
decision, write a new ADR with status `Proposed` and ask me. Never set an ADR
to `Accepted`.
