# GTA VI - PATCH DOWNLOADED

A PS4 homebrew project scaffold for a patch-information viewer and compatibility checker.

## Safety and compatibility

The configured source page is `https://prosperopatches.com/PPSA29660?v=01.002.001`.
The title identifier `PPSA29660` belongs to a PS5 title. This project must not present that patch as installable on a PS4. The first milestone therefore focuses on showing source metadata and clearly reporting platform incompatibility. It does not download, decrypt, install, or modify game packages.

Only use update files for titles and devices you own and are authorized to update. The app will not bypass platform signatures, licensing, or system protections.

## Project layout

- `app/` — native application source and patch metadata model
- `config/` — source page and known title metadata
- `assets/` — app artwork source
- `.github/workflows/` — CI build entry point
- `Makefile` — OpenOrbis build rules

## Build status

Milestone 1 establishes the project structure and PS4-native build configuration. A successful PKG requires the OpenOrbis PS4 toolchain and its packaging utilities; CI will publish a PKG only after all build and packaging steps succeed.

## Target

- Display name: **GTA VI - PATCH DOWNLOADED**
- Platform: PS4 homebrew shell
- Initial source record: PS5 title update metadata, marked **NOT COMPATIBLE WITH PS4**
- Visual direction: black background with neon-red accents

## References

- [OpenOrbis PS4 Toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain)
- [OpenOrbis SDL sample build layout](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/tree/master/samples/SDL2)
