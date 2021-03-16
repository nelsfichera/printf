#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdlib.h>	/* malloc, free */
#include <stdarg.h>	/* vargs */
#include <unistd.h>	/* write */

/**
* struct functions - struct for calling functions
* @type: identifies which function to use
* @function: pointer to the function called by type
*/
typedef struct functions
{
	 char type;
	 char *(*function)(va_list);

} func_t;

/*main printing functions*/
char *(*getfunction(char n))(va_list);
int output(char *string, char *buffer, int buffer_size, int start, int mode);
int _printf(const char *format, ...);
int _strlen(char *string);

/*functions being called by type*/
char *format_binary(va_list);
char *format_char(va_list);
char *format_decimal(va_list);
char *format_hex(va_list);
char *format_octal(va_list);
char *format_percent();
char *format_reverse(va_list);
char *format_rot13(va_list);
char *format_string(va_list);
char *format_unsigned(va_list);
#endif	/* HOLBERTON_H */
