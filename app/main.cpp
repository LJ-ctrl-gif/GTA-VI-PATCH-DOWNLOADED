#include <stdio.h>
#include <string.h>
#include <sstream>
#include <unistd.h>

#include "patch_catalog.h"
#include "graphics.h"

std::stringstream debugLogStream;

static const char kSymbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.:/ ";
static const unsigned char kFont[][5] = {
    {2,5,7,5,5}, {6,5,6,5,6}, {3,4,4,4,3}, {6,5,5,5,6},
    {7,4,6,4,7}, {7,4,6,4,4}, {3,4,5,5,3}, {5,5,7,5,5},
    {7,2,2,2,7}, {1,1,1,5,2}, {5,5,6,5,5}, {4,4,4,4,7},
    {5,7,7,5,5}, {5,7,7,7,5}, {2,5,5,5,2}, {6,5,6,4,4},
    {2,5,5,7,3}, {6,5,6,5,5}, {3,4,2,1,6}, {7,2,2,2,2},
    {5,5,5,5,7}, {5,5,5,5,2}, {5,5,7,7,5}, {5,5,2,5,5},
    {5,5,2,2,2}, {7,1,2,4,7},
    {7,5,5,5,7}, {2,6,2,2,7}, {6,1,2,4,7}, {6,1,2,1,6},
    {5,5,7,1,1}, {7,4,6,1,6}, {3,4,6,5,2}, {7,1,2,2,2},
    {2,5,2,5,2}, {2,5,3,1,6},
    {0,0,7,0,0}, {0,0,0,0,2}, {0,2,0,2,0}, {1,1,2,4,4},
    {0,0,0,0,0}
};

static void drawText(Scene2D* scene, const char* text, int x, int y, int scale, Color color) {
    for (size_t i = 0; text[i] != '\0'; ++i) {
        const char* found = strchr(kSymbols, text[i]);
        if (!found) {
            x += 4 * scale;
            continue;
        }
        const int index = static_cast<int>(found - kSymbols);
        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (kFont[index][row] & (1u << (2 - col))) {
                    scene->DrawRectangle(x + col * scale, y + row * scale,
                                         scale, scale, color);
                }
            }
        }
        x += 4 * scale;
    }
}

static void drawInterface(Scene2D* scene, const PatchRecord& patch) {
    const Color background = {5, 6, 10};
    const Color panel = {15, 18, 27};
    const Color panel2 = {22, 25, 36};
    const Color red = {255, 25, 65};
    const Color redDark = {74, 9, 25};
    const Color white = {240, 243, 250};
    const Color muted = {145, 153, 170};

    scene->FrameBufferFill(background);
    scene->DrawRectangle(70, 55, 1780, 970, panel);
    scene->DrawRectangle(70, 55, 1780, 9, red);
    scene->DrawRectangle(70, 55, 9, 970, red);

    drawText(scene, "GTA VI PATCH DOWNLOADED", 125, 115, 7, white);
    drawText(scene, "PATCH MANAGER  /  PS4 HOMEBREW", 128, 205, 4, muted);
    scene->DrawRectangle(125, 270, 1670, 2, panel2);

    scene->DrawRectangle(125, 325, 1670, 300, panel2);
    scene->DrawRectangle(125, 325, 10, 300, red);
    drawText(scene, "SOURCE PATCH", 175, 365, 4, red);
    drawText(scene, "TITLE ID", 175, 445, 3, muted);
    drawText(scene, patch.titleId, 175, 485, 5, white);
    drawText(scene, "VERSION", 750, 445, 3, muted);
    drawText(scene, patch.version, 750, 485, 5, white);
    drawText(scene, "SOURCE PLATFORM", 1280, 445, 3, muted);
    drawText(scene, patch.sourcePlatform, 1280, 485, 5, white);

    scene->DrawRectangle(125, 690, 1670, 245, redDark);
    scene->DrawRectangle(125, 690, 1670, 8, red);
    drawText(scene, "INCOMPATIBLE PLATFORM", 175, 735, 6, red);
    drawText(scene, "THIS UPDATE TARGETS PS5 - NOT PS4", 175, 820, 4, white);
    drawText(scene, "DOWNLOAD DISABLED", 1280, 820, 4, red);
    drawText(scene, "BUILD 0.1  /  COMPATIBILITY CHECK ACTIVE", 128, 970, 3, muted);
}

int main(int, char**) {
    const PatchRecord& patch = GetConfiguredPatch();
    Scene2D* scene = new Scene2D(1920, 1080, 4);

    if (!scene->Init(0xC000000, 2)) {
        printf("GTA VI - PATCH DOWNLOADED: video initialization failed.\n");
        for (;;) sleep(1);
    }

    scene->SetActiveFrameBuffer(0);
    drawInterface(scene, patch);
    scene->SubmitFlip(0);
    scene->FrameWait(0);

    scene->FrameBufferSwap();
    drawInterface(scene, patch);
    scene->SubmitFlip(1);
    scene->FrameWait(1);

    for (;;) sleep(1);
    return 0;
}
