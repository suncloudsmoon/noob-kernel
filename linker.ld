OUTPUT_FORMAT(elf32-i386)
ENTRY(_noob_kernel)

SECTIONS {
    . = 1M;
    .text BLOCK(4K) : ALIGN(4K) {
        *(.text)
    }
    .bss BLOCK(4K) : ALIGN(4K) {
        *(.bss)
    }
    .data BLOCK(4K) : ALIGN(4K) {
        *(.data)
    }
}
