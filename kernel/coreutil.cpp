/*
 * Copyright (c) 2021, suncloudsmoon and the noob-kernel contributors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "../include/kernel/coreutil.hpp"
#include "../include/kernel/coreconsts.hpp"

namespace core {
    void clear_screen() {
        for (int y = 0; y <= VGA_SCREEN_HEIGHT; y++) {
            for (int x = 0; x <= VGA_SCREEN_WIDTH; x+=2) {
                int pos = (y * VGA_SCREEN_WIDTH) + x;
                put_char(pos, ' ');
            }
        }
    }
    // See https://wiki.osdev.org/Printing_To_Screen
    void put_char(int pos, char c) {
        vga[pos] = c;
        vga[pos + 1] = WHITE_COLOR_VGA;
    } 
}