#include <stdarg.h>

#include "../include/lib/io.hpp"
#include "../include/lib/str.hpp"
#include "../include/coreconsts.hpp"

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

                    int index = 0;
                    while (char z = str[index++]) {
                        put_auto_char(z);
                    }
                    vga[0] = 'a';
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
