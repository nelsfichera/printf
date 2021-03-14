#include "holberton.h"

/* Buffer management function */

int _printf(const char *format, ...)
{
	/* Make buffer */
	char buffer[1024];
	/* Number of bytes printed */
	int byte_count;
	int x; 			/* Iterator for format string */
	va_list arguments;
/* Table of functions which correspond to format specifiers */
	func_t func_table[] = {
		{'c', format_char},
		{'s', format_string},
		{'%', format_percent},
		{'d', format_decimal},
		{'i', format_decimal},
	};

	va_start(arguments, format);

	/* itterate over format string and search for format specifications */
	for (x = 0; format[x]; x++)
	{
		if (format[x] == '%')
		{
		/* Lookup and call format specifier interpreter func */
	        /* Whichever function gets called should return a formatted string */
		/* That string goes to the output */
		}
		/* Move stuff to buffer */
		/* output( string ); */
	}

	va_end(arguments);
	return (byte_count);
}
