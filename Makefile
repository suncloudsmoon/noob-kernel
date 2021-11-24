
bin/noob_kernel.bin: boot/boot.asm kernel/entry.cpp
	nasm -f elf32 boot/boot.asm -o bin/boot.o
	g++ -m32 -c kernel/entry.cpp -o bin/entry.o
	ld -m elf_i386 -T linker.ld bin/*.o -o bin/noob_kernel.bin
