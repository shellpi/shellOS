/*************************************
 * file: utils.c
 * description: Kernel utils module
 * output: utils.o
 *************************************/

#include <stdint.h>


static inline void sleep(int32_t count) {
	asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
		: "=r"(count) : [count] "0"(count) : "cc");
}

// A Mailbox message with set clock rate of PL011 to 3MHz tag
volatile unsigned int  __attribute__((aligned(16))) mbox[9] = {
	9 * 4, 0, 0x38002, 12, 8, 2, 3000000, 0 ,0
};