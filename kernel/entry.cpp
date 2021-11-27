#include "../include/debugmode.hpp"
#include "../include/lib/mem.hpp"
#include "../include/kernel/coreutil.hpp"
#include "../include/lib/io.hpp"
#include "../include/lib/str.hpp"
#include "../include/lib/math.hpp"

/*
 * Command used to test this kernel:
 * qemu-system-i386 -kernel bin/noob_kernel.bin
 */

// NOTE: the entry function must be called noob_start(): defined in boot.asm
/*
 * General Rules:
 * Except for some definitions, the C++ standard lib should not be used
 * When the C++ standard lib is used, a comment must follow it
 */

// Required stuff by GCC
extern "C" {
#ifdef __GNUC__
    void __stack_chk_fail_local() {

    }
    void __cxa_guard_acquire() {

    }
    void __cxa_guard_release() {

    }
#endif
}

class A {
    public:
        A() {
            a = 5;
        }
        int getA() {
            return a;
        }  
    private:
        int a;    
};

extern "C" {
    void noob_start() { 
        core::clear_screen();
        char *something = (char *) nlib::malloc(34);

        // Testing if malloc works in A class
        A *test_malloc = new A();
        nlib::printf("A is %d!", test_malloc->getA());
    }
}

