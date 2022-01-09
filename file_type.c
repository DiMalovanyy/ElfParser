#include "file_type.h"
#include <elf.h>

enum SystemBit get_architecture(uint8_t* mem) {
	uint8_t* e_indent = mem;

	switch (e_indent[EI_CLASS]) {
		case ELFCLASS32: return X32;
		case ELFCLASS64: return X64;		 
		default: return UNDEFINED;
	}
}
