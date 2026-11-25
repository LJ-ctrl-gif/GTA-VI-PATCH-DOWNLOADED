#pragma once

struct PatchRecord {
    const char* titleId;
    const char* version;
    const char* sourcePlatform;
    const char* targetPlatform;
    bool compatible;
    const char* statusMessage;
};

const PatchRecord& GetConfiguredPatch();
