#include <stdint.h>

enum SystemBit { X32, X64, UNDEFINED };
enum SystemBit get_architecture(uint8_t* mem);
