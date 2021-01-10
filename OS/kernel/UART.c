/************************************************************
 * file: UART.c
 * description: Universal asynchronous receiver-transmitter
 * include: MMIO.o, utils.o
 * output: UART.o
 ************************************************************/

#include "settings.h"


void UART_init() {
	memwrite(UART0_CR, 0x00000000);
	memwrite(GPPUD, 0x00000000);
	sleep(150);

	memwrite(GPPUDCLK0, (1 << 14) | (1 << 15));
	sleep(150);

	memwrite(GPPUDCLK0, 0x00000000);
	memwrite(UART0_ICR, 0x7FF);

	if (RASPI >= 3) {
		unsigned int r = (((unsigned int)(&mbox) & ~0xF) | 8);
		while (memread(MBOX_STATUS) & 0x80000000) {}
		memwrite(MBOX_WRITE, r);
		while ((memread(MBOX_STATUS) & 0x40000000) || memread(MBOX_READ) != r) {}
	}

	memwrite(UART0_IBRD, 1);
	memwrite(UART0_FBRD, 40);
	memwrite(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));
	memwrite(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
	                     (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));
	memwrite(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
}
// UART initializer

void UART_putc(unsigned char c) {
	while (memread(UART0_FR) & (1 << 5)) {}
	memwrite(UART0_DR, c);
}

unsigned char UART_getc() {
	while (memread(UART0_FR) & (1 << 4)) {}
	return memread(UART0_DR);
}

void UART_puts(char* s) {
	for (unsigned i = 0; s[i]; i++)
		UART_putc(s[i]);
}
// UART I/O