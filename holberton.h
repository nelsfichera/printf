#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdlib.h> 		/* malloc, free */
#include <stdarg.h>		/* vargs */
#include <unistd.h> 		/* write */

int _printf(const char *format, ...);
typedef struct functions
{
	 char letter;
	 void (*f)();

} func_t;
#endif	/* HOLBERTON_H */
