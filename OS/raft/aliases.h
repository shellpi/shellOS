#ifndef __SHELLOS_RAFT_ALIASES_H__
#define __SHELLOS_RAFT_ALIASES_H__

#if !defined(_WIN32) || !defined(linux) || !defined(__MACH__)
 #define putch(c) UART_putc(c)
 #define puts(s) UART_puts(s)
 #define getc UART_getc
#else
 #include <stdio.h>
 #define putch(c) putchar(c)
#endif
// support for Windows, OSX, LINUX...


#endif // ! __SHELLOS_RAFT_ALIASES_H__
