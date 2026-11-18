# Project instructions

From the project root (with GNU Make, including inside the Dev Container):

- Build: `make build`
- Run: `make run`
- Test: `make test`
- Clean: `make clean`

Architecture decisions are in `docs/adr/`. Read them before changing the
build, tools, or test setup. Never go against an accepted ADR. To change a
decision, write a new ADR with status `Proposed` and ask me. Never set an ADR
to `Accepted`.

See `CONTRIBUTING.md` for the development setup, TDD workflow, and ADR
guidance. GitHub issue and pull request templates are in `.github/`; pull
request CI is defined in `.github/workflows/ci.yml` and documented in
`docs/adr/0005-github-actions-ci.md`.
