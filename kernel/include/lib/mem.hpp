#ifndef MEM_HPP
#define MEM_HPP

#include <stddef.h>

    constexpr long MEM_SIZE = 256 * 256;
    extern unsigned char stack[MEM_SIZE];
    void* malloc(size_t size) {
        static size_t index = 0;
        if (index >= MEM_SIZE) {
            return nullptr;
        }
        void *ptr = stack + index;
        index += size;
        return ptr;
    }
    void free(void* ptr) {
        ptr = nullptr;
    }
// void* operator new(size_t size) {
//     return nlib::malloc(size);
// }

// void* operator new[](size_t size) {
//     return nlib::malloc(size);
// }

// void operator delete(void *ptr) {
//     nlib::free(ptr);
// }

// void operator delete[](void *ptr) {
//     nlib::free(ptr);
// }


#endif /* MEM_HPP */