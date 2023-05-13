all: 
	nasm -fbin src/boot.asm -o out/os.bin
	nasm -fbin src/kernel.asm -o out/kernel.bin
	type out\kernel.bin >> out\os.bin
	qemu-system-i386 out/os.bin