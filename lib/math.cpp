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

#include "../include/lib/math.hpp"

static unsigned long x = 0;

namespace nlib {
    void srand(unsigned long seed) {
        x = seed;
    }
    // See: https://en.wikipedia.org/wiki/Linear_congruential_generator
    unsigned long rand(unsigned long start, unsigned long end) {
        const unsigned long a = 8121;
        const unsigned long c = 28411;
        const unsigned long m = 134456;
        x = (a * x + c) % m;
        return x % (end - start) + start;
    }
}
