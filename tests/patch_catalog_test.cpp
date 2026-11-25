#include <cassert>
#include <cstring>
#include "../app/patch_catalog.h"

int main() {
    const PatchRecord& patch = GetConfiguredPatch();

    assert(std::strcmp(patch.titleId, "PPSA29660") == 0);
    assert(std::strcmp(patch.version, "01.002.001") == 0);
    assert(std::strcmp(patch.sourcePlatform, "PS5") == 0);
    assert(std::strcmp(patch.targetPlatform, "PS4") == 0);
    assert(patch.compatible == false);
    assert(std::strstr(patch.statusMessage, "INCOMPATIBLE") != nullptr);

    return 0;
}
