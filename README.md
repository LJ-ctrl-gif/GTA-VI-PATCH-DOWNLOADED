# GTA VI - PATCH DOWNLOADED

A PS4 homebrew project for a patch-information viewer and compatibility checker.

## Current application

The native interface uses a black background with neon-red accents and has three controller-selectable screens: **Patch Info**, **Compatibility**, and **About**. Build 0.9 displays live controller connection status. Build 0.8 adds a persistent offline-viewer indicator and three page-position markers. Build 0.6 explicitly states that no patch file is bundled with the app. It also retains the offline-only notice and confirms that network access is not implemented. Build 0.3 introduced the static-metadata label and repeated PS5-to-PS4 incompatibility warning. Use the DualShock 4 D-pad left/right buttons to switch screens. The patch screen displays the configured title ID, version, source platform, and compatibility status.

The configured source page is `https://prosperopatches.com/PPSA29660?v=01.002.001`.
The title identifier `PPSA29660` is identified in this project as a PS5 title. The app marks it **NOT COMPATIBLE WITH PS4** and keeps download disabled. This is a metadata-based compatibility notice, not a live device or package inspection. It does not download, decrypt, install, or modify game packages.

Only use update files for titles and devices you own and are authorized to update. The app will not bypass platform signatures, licensing, or system protections.

## Project layout

- `app/` — native application source, patch model, and screen UI
- `config/` — source page and known title metadata
- `assets/` — app artwork source
- `tests/` — host-side compatibility guard test
- `.github/workflows/` — CI build and PKG artifact workflow
- `Makefile` — OpenOrbis PS4 build rules

## Build pipeline

The GitHub Actions workflow:
1. Runs the patch compatibility test.
2. Downloads the pinned OpenOrbis v0.5.4 toolchain and verifies its archive hash.
3. Generates a 512x512 PS4 icon from the SVG artwork.
4. Compiles the native PS4 application.
5. Packages the output as a PKG and uploads it as a workflow artifact.

A PKG is not considered ready until the workflow completes successfully. Build 0.8 includes the three-screen interface, offline status indicator, and page-position markers. Build 0.7 introduced the metadata-based compatibility clarification and includes the three-screen interface, controller navigation, explicit offline-only status, a no-patch-file notice, and a clarification that compatibility is based on configured metadata. Live webpage retrieval and a download queue are not implemented.

## Target

- Display name: **GTA VI - PATCH DOWNLOADED**
- Platform: PS4 homebrew
- Initial source record: PS5 patch metadata, marked **NOT COMPATIBLE WITH PS4**
- Visual direction: black background with neon-red accents

## References

- [OpenOrbis PS4 Toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain)
- [OpenOrbis graphics sample](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/tree/v0.5.4/samples/graphics)
