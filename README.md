# GTA VI - PATCH DOWNLOADED

A native PS4 homebrew information viewer for the user-reported GTA VI title entry.

## Current behavior

The application has three controller-selectable screens: Patch Info, Compatibility, and About. The configured title ID is `PPSA38500`, based on the user's report of the installed entry.

The displayed patch version is intentionally marked `UNVERIFIED`. A title ID or store listing does not prove that a package contains a native PS4 executable. The application does not include GTA VI game data, a patch payload, a downloader, or an installer.

## Compatibility notice

The available public platform information identifies GTA VI as a PS5 title. This app therefore treats `PPSA38500` as PS5 title metadata and does not claim that it is a PS4 game. It will not download or install a PS5 package on PS4.

## Controls

Use the DualShock 4 D-pad left/right buttons to switch between Patch Info, Compatibility, and About.

## Build pipeline

GitHub Actions runs the catalog test, downloads the pinned OpenOrbis toolchain, builds the native executable, packages it as a PS4 PKG, and publishes the build artifact/release according to workflow settings.

A successful CI build confirms compilation and packaging only. It does not certify that an unrelated game or patch package is compatible with PS4. Test the app on the target console before treating a release as verified.

## Target

- Application: GTA VI - PATCH DOWNLOADED
- Platform: PS4 homebrew information viewer
- Displayed title ID: PPSA38500 (user-reported)
- Patch version: Unverified
- Game/patch payload: Not included
- Visual theme: black with neon-red accents
