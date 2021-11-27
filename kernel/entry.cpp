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

        A *test_malloc = new A();
        // nlib::printf("A is %d!", test_malloc->getA());
        for (int i = 0; i < 1; i++)
            nlib::printf("%c", '\n');
        nlib::printf("Success!");    
        
        // nlib::printf("ceil(5) is %c!", nlib::to_char(nlib::ceil(5)));
    }
}

