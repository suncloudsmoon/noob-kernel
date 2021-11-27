BOOT_SRC = boot/boot.asm
BOOT_OBJ = bin/boot.o
SOURCES_SRC = $(wildcard kernel/*.cpp) $(wildcard lib/*.cpp)
SOURCES_OBJ = bin/kernel.o
KERNEL_BIN = bin/noob_kernel.bin

INCLUDE_DIR = kernel/include 

# NOTE: -r is very important
# https://stackoverflow.com/questions/2980102/combine-two-gcc-compiled-o-object-files-into-a-third-o-file
# https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html

bin/noob_kernel.bin: $(BOOT_SRC) $(SOURCES_SRC)
	nasm -f elf32 $(BOOT_SRC) -o $(BOOT_OBJ)
	g++ -static -O2 -std=c++2a -m32 -r -I$(INCLUDE_DIR) $(SOURCES_SRC) -o $(SOURCES_OBJ)
	ld -m elf_i386 -T linker.ld $(BOOT_OBJ) $(SOURCES_OBJ) -o $(KERNEL_BIN)
