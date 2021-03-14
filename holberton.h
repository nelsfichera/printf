#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdlib.h>	/* malloc, free */
#include <stdarg.h>	/* vargs */
#include <unistd.h>	/* write */
char *(getfunction(char n));
char *make_buffer(void);
void print_buffer(char *buffer, int length, va_list arguments);
int buffer_dealer(char *buffer, int length);
int _printf(const char *format, ...);
typedef struct functions
{
	 char type;
	 void (*f)();

} func_t;
int format_rot13(va_list string);
char *format_binary(va_list argument);
char *format_octal(va_list argument);
#endif	/* HOLBERTON_H */
