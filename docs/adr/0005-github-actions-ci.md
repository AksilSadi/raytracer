# 0005: Run pull-request checks with GitHub Actions

## Context

The project needs automated build and test checks on every pull request using
the same environment as contributors. Running checks manually is the
alternative.

## Decision

Use GitHub Actions to build the existing Dev Container image and run `make test`
inside it for pull requests.

## Status

Proposed

## Consequences

Pull requests receive automated build and test checks in the project's
container environment. The workflow depends on GitHub Actions, its
`actions/checkout` action, and a GitHub-hosted Ubuntu runner, and therefore is
tied to the GitHub service.
