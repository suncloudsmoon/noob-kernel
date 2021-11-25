#include "coreutil.hpp"
#include "coreconsts.hpp"

namespace core {
    void clear_screen() {
        for (int y = 0; y < VGA_SCREEN_HEIGHT; y++) {
            for (int x = 0; x < VGA_SCREEN_WIDTH; x+=2) {
                int pos = y * VGA_SCREEN_WIDTH + x;
                vga[pos] = 0x0;
                vga[pos + 1] = 0x0;
            }
        }
    }
}