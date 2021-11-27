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

#include <stdarg.h>

#include "../include/lib/io.hpp"
#include "../include/lib/str.hpp"
#include "../include/kernel/coreconsts.hpp"

static int itoa(int val, char *str, int str_size);

static void put_auto_char(char c);
static void put_char(char c, int pos);
template<class T>
static constexpr T convert_to_1d_pos(T x, T y, T width);

namespace nlib {
    int printf(const char *format, ...) {
        int index = 0;
        va_list args;
        va_start(args, format);
        while (char c = format[index++]) {
            if (c == '%') {
                char f = format[index++];
                if (f == 'd') {
                    int num = va_arg(args, int);
                    char str[100] = {0};
                    itoa(num, str, sizeof(str) - 2);
                    printf("%s", str);
                } else if (f == 'c') {
                    int a = va_arg(args, int);
                    put_auto_char(static_cast<char>(a));
                } else if (f == 's') {
                    const char *str = va_arg(args, char *);
                    int i = 0;
                    while (char z = str[i++]) { put_auto_char(z); }
                } else {
                    put_auto_char(f);
                }
            } else {
                put_auto_char(c);
            }
        }
        va_end(args);
        return 0;
    }
}

static void put_auto_char(char c) {
    static int x = 0, y = 0;
    // bounds checking
    if (x >= VGA_SCREEN_WIDTH) {
        x = 0;
        y++;
    }
    int screen_pos = convert_to_1d_pos(x, y, VGA_SCREEN_WIDTH);
    put_char(c, screen_pos);
    x += 2;
}

// See https://wiki.osdev.org/Printing_To_Screen
static void put_char(char c, int pos) {
    vga[pos] = c;
    vga[pos + 1] = WHITE_COLOR_VGA;
} 

template<class T>
static constexpr T convert_to_1d_pos(T x, T y, T width) {
    return (y * width) + x;
}
