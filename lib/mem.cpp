#include "../include/lib/mem.hpp"

namespace nlib {
    unsigned char mem[200];
    void* malloc(size_t size) {
        static size_t index = 0;
        void *ptr = static_cast<void*>(mem + index);
        index += size;
        return ptr;
    }
    void free(void *ptr) {
        // Log freed stuff
    }
}

void* operator new(size_t size) {
    return nlib::malloc(size);
}

void* operator new[](size_t size) {
    return nlib::malloc(size);
}

void operator delete(void *ptr) {
    nlib::free(ptr);
}

void operator delete[](void *ptr) {
    nlib::free(ptr);
}