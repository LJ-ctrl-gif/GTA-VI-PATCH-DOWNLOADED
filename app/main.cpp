#include <stdio.h>
#include "patch_catalog.h"

int main(int, char**) {
    const PatchRecord& patch = GetConfiguredPatch();

    printf("\n");
    printf("==============================================\n");
    printf("       GTA VI - PATCH DOWNLOADED\n");
    printf("==============================================\n");
    printf("SOURCE TITLE : %s\n", patch.titleId);
    printf("PATCH VERSION: %s\n", patch.version);
    printf("SOURCE       : %s\n", patch.sourcePlatform);
    printf("THIS DEVICE  : %s\n", patch.targetPlatform);
    printf("----------------------------------------------\n");
    printf("%s\n", patch.statusMessage);
    printf("----------------------------------------------\n");
    printf("Milestone 1 bootstrap. Network retrieval and\n");
    printf("graphical interface are not enabled yet.\n");
    printf("\n");

    return 0;
}
