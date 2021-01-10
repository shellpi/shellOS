/************************************************
 * file: kernel.c
 * description: shellOS kernel main file
 * include: UART.o, MMIO.o, utils.o, alloc.o
 * output: kernel.o
 ************************************************/

#include <stdint.h>
#include "settings.h"


#if defined(__cplusplus)
extern "C"
#endif

#ifdef AARCH64
void shell_kernel(uint64_t dtb_ptr32, uint64_t x1, uint64_t x2, uint64_t x3)
#else
void shell_kernel(uint32_t r0, uint32_t r1, uint32_t atags)
#endif
{
	main();
	return;
}