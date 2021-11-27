;
; Copyright (c) 2021, suncloudsmoon and the noob-kernel contributors.
; 
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so.
; 
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
; SOFTWARE.

; This is the bootloader
; Max space it should take is 512 bytes
section .text
; Magic stuff here
; dd == double word => 4 bytes 
dd 0x1BADB002 ; real magic num
dd 0x0 ; args
dd - (0x1BADB002) ; something is checked here

; external c function
extern noob_start

; entry into bootloader
global _noob_kernel

_noob_kernel:
    call noob_start ; check c file after this
    hlt ; No idea what happens if the cpu didn't halt
