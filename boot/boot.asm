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
