#include "patch_catalog.h"

static const PatchRecord kConfiguredPatch = {
    "PPSA38500",
    "UNVERIFIED",
    "PS5",
    "PS4",
    false,
    "PS5 TITLE METADATA ONLY: no verified PS4 game or patch payload is available."
};

const PatchRecord& GetConfiguredPatch() {
    return kConfiguredPatch;
}
