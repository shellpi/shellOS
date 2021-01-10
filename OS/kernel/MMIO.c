/**********************************
 * file: MMIO.c
 * description: Memory-mapped I/O
 * output: MMIO.o
 **********************************/

#include <stdint.h>


static inline uint32_t memread(uint32_t reg) {
	return *(volatile uint32_t*)reg;
}

static inline void memwrite(uint32_t reg, uint32_t data) {
	*(volatile uint32_t*)reg = data;
}