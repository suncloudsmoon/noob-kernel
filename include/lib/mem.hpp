#ifndef MEM_HPP
#define MEM_HPP

#include <stddef.h>

namespace nlib {
    void* malloc(size_t size);
    void free(void *ptr);
}

void* operator new(size_t size);
void* operator new[](size_t size);
void operator delete(void *ptr);
void operator delete[](void *ptr);

#endif /* MEM_HPP */