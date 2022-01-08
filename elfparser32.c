
/* Elf marser for x32 systems */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <elf.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	int fd, i;
	uint8_t *mem;
	struct stat st;

	char *StringTable, *interp;

	Elf32_Ehdr *ehdr; // ELF header
	Elf32_Phdr *phdr; // Programm header
	Elf32_Shdr *shdr; // Section header

	if (argc < 2) {
		printf("Usage: %s <executable> \n", argv[0]);
		exit(0);
	}

	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		perror("open");
		exit(-1);
	}

	if (fstat(fd, &st) < 0) {
		perror("fstat");
		exit(-1);
	}

	/* Map executable into memory */ 
	mem = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (mem == MAP_FAILED) {
		perror("mmap");
		exit(-1);
	}

	/* The initial ELF Header starts ar offset 0 of our mapped memory */
	ehdr = (Elf32_Ehdr*)mem;

	/* The shdr table and phdr table offsets are
	 * given by the e_shoff and e_phoff members of the Elf32_Ehdr */
	phdr = (Elf32_Phdr*)&mem[ehdr->e_phoff];
	shdr = (Elf32_Shdr*)&mem[ehdr->e_shoff];




}
