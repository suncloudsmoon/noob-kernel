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
