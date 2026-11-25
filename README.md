# GTA VI - PATCH DOWNLOADED

A native PS4 homebrew application for displaying patch metadata and platform compatibility.

## Current behavior

The application has three controller-selectable screens: Patch Info, Compatibility, and About. It displays the configured source record from:

`https://prosperopatches.com/PPSA29660?v=01.002.001`

The record identifies title `PPSA29660`, version `01.002.001`, and source platform PS5. The app explicitly marks it incompatible with PS4. It does not include a game, patch payload, download queue, decryptor, or installer.

## PS4 package metadata

The package Content ID has been normalized to uppercase:

`IV0000-GTAD00001_00-GTAVIPATCHDOWNLD`

This change addresses a suspected package-identifier formatting problem associated with the previously reported Package Installer rejection code. It is a build-side correction, not proof of successful installation or launch. The app must still be tested on the target PS4.

## Build pipeline

GitHub Actions runs the compatibility test, downloads the pinned OpenOrbis v0.5.4 toolchain, generates the PS4 icon, builds the native executable, packages it as a PKG, and uploads the resulting artifact and release asset.

A successful CI build confirms compilation and packaging only. It does not certify runtime behavior on a physical PS4. Test installation and launch on the target console before treating the release as verified.

## Controls

Use the DualShock 4 D-pad left/right buttons to switch between Patch Info, Compatibility, and About.

## Target

- Application: GTA VI - PATCH DOWNLOADED
- Platform: PS4 homebrew
- Source record: PS5 patch metadata
- Compatibility with PS4: Not compatible
- Visual theme: black with neon-red accents

## References

- [OpenOrbis PS4 Toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain)
- [Prospero Patches source record](https://prosperopatches.com/PPSA29660?v=01.002.001)
