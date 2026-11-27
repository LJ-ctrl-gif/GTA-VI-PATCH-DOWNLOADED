#include <cassert>
#include <cstring>
#include "../app/patch_catalog.h"

int main() {
    const PatchRecord& patch = GetConfiguredPatch();

    assert(std::strcmp(patch.titleId, "PPSA38500") == 0);
    assert(std::strcmp(patch.version, "UNVERIFIED") == 0);
    assert(std::strcmp(patch.sourcePlatform, "PS5") == 0);
    assert(std::strcmp(patch.targetPlatform, "PS4") == 0);
    assert(patch.compatible == false);
    assert(std::strstr(patch.statusMessage, "PS5") != nullptr);

    return 0;
}
