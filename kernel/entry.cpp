#include "include/debugmode.hpp"
#include "include/coreutil.hpp"
#include "include/lib/io.hpp"
#include "include/lib/str.hpp"
#include "include/lib/math.hpp"
#include "include/lib/mem.hpp"

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
        
        char str[10] = {0};
        char *str_ptr = str;
        nlib::itoa(32353, str_ptr, 10);
        
        float a = nlib::pow<float>(4.f,0.5f);

        char *something = (char *) malloc(34);

        nlib::printf("%d", 5);
    }
}

