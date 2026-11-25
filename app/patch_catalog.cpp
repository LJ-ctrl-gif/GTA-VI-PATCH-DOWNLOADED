#include "patch_catalog.h"

static const PatchRecord kConfiguredPatch = {
    "PPSA29660",
    "01.002.001",
    "PS5",
    "PS4",
    false,
    "INCOMPATIBLE: this patch belongs to a PS5 title and is not installable on PS4."
};

const PatchRecord& GetConfiguredPatch() {
    return kConfiguredPatch;
}
