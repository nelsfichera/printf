#include "holberton.h"

/**
* get_function - get the function
* @n: identifier for function
* Return: function pointer
*/
char *(get_function(char n))
{ 
	int x  = 0; /*for iteration*/ 
	func_t func_table[] = {
		{'c', format_char},
		{'s', format_string},
		{'%', format_percent},
		{'d', format_decimal},
		{'i', format_decimal},
		{'b', format_binary},
		{'R', format_rot13},
		{'o', format_octal},
	};
	/*"type/function" to be defined in header, nomenclature to be settled on with JM*/
	while (func_table[x].type != '0')
	{
		if (func_table[x].type == n)
			return(func_table[x].function);
		x++;
	}
	return (NULL);
}
/* Buffer management functions-- if they can be compounded into a single function that would be prime*/
/**
* make_buffer - create a buffer to hold a string until ready for printing 
* Return: pointer to the created buffer
*/
char *make_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char * 1024);
			if (buffer == NULL)
			return(NULL);
			return(buffer);
}
/**             
* print_buffer - prints the buffer, reallocates, and frees
* @buffer: buffer
* @length: length of the string 
* @arguments: va_list
*/
void print_buffer(char *buffer, int length, va_list arguments)
{
	char *buffer;
	
	/*realloc for correct size, no overflow*/
	buffer = realloc(buffer, length);
	/*print*/
	write(1, buffer, length);
	/*free, deinitialize*/
	free(buffer);
	va_end(arguments);
}
/**
* buffer_dealer - when writing over buffer space, prints everything 
* and then reverts length to zero and starts writing at buffer start
* @buffer: the buffer 
* @length: length of string
* Return: position
*/
int buffer_dealer(char *buffer, int length)
{
	if (length > 1020)
	{
		write(1, buffer, length);
		length = 0;
	}
	return (length);
}
/**
* _printf - manages sub-functions, returns number of bytes
* format - the format to be executed on a string
* Return - number of bytes, output printed string
*/
int _printf(const char *format, ...)
{
	/* Make buffer */
	/*char buffer[1024];*/
	/* Number of bytes printed */
	int byte_count;
	int x; 			/* Iterator for format string */
	va_list arguments;
	va_start(arguments, format);

	/* iterate over format string and search for format specifications */
	for (x = 0; format[x]; x++)
	{
		if (format[x] == '%')
		{
		/* Lookup and call format specifier interpreter func using get_function */
	        /* Whichever function gets called should return a formatted string */
		/* That string goes to the output */
		}
		/* Move stuff to buffer */
		/* output( string ); */
	}

	va_end(arguments);
	return (byte_count);
}
