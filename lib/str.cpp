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

#include "../include/lib/str.hpp"

namespace nlib {
    /*
NOTE: str_size excluding the null terminator
*/
    int itoa(int val, char *str, int str_size) {
        char arr[MAX_ITOA_PRECISION] = {0};
        int arrIndex = MAX_ITOA_PRECISION - 1;
        if (val == 0) {
            arr[arrIndex] = to_char(0);
        } else {
            while (arrIndex >= 0 && val != 0) {
                arr[arrIndex] = to_char(val % 10);
                val /= 10;
                arrIndex--;
            }
        }
        arrIndex++;
        int i;
        for (i = 0; i < str_size - 1; i++) {
            if (arrIndex > MAX_ITOA_PRECISION - 1)
                break;
            str[i] = arr[arrIndex];
            arrIndex++;
        }
        str[i] = '\0';
        return 0;
    }
}