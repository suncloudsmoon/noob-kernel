#include "include/debugmode.hpp"
#include "include/coreutil.hpp"
#include "include/lib/io.hpp"
#include "include/lib/str.hpp"

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
#endif
}

extern "C" {
    void noob_start() {
        core::clear_screen();
        char str[10] = {0};
        char *str_ptr = str;
        nlib::itoa(32353, str_ptr, 10);
        nlib::printf("%s", str_ptr);
    }
}

