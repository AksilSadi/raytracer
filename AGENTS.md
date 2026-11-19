# Project instructions

From the project root (with GNU Make, including inside the Dev Container):

- Build: `make build`
- Run: `make run`
- Test: `make test`
- Clean: `make clean`

## Source layout

New classes go in the folder for their concept under `src/`, and their tests
go in the matching folder under `tests/`. Include project headers by their path
from `src/`, for example `#include "math/vector.h"`.

## How we work

- Use TDD: write a failing test first, then only enough code to make it pass.
- Derive expected values from the maths, not from running the code. If a test
  fails, ask me before changing its expected value.
- Work one small step at a time and change only what I ask for.
- Keep the C++ simple; do not use advanced features unless I ask.
- Do not build or run on the host. Run project commands in the Dev Container.

Architecture decisions are in `docs/adr/`. Read them before changing the
build, tools, or test setup. Never go against an accepted ADR. To change a
decision, write a new ADR with status `Proposed` and ask me. Only the project
owner may set an ADR to `Accepted`.

See `CONTRIBUTING.md` for the development setup, TDD workflow, and ADR
guidance. GitHub issue and pull request templates are in `.github/`; pull
request CI is defined in `.github/workflows/ci.yml` and documented in
`docs/adr/0005-github-actions-ci.md`. The source and test layout is documented
in `docs/adr/0006-organize-code-by-concept.md`.
