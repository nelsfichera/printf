#include "holberton.h"

#if 0
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

	buffer = malloc(sizeof(char * 1024));
	if (buffer == NULL)
		return(NULL);
	return (buffer);
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
#endif

/**
 * output - a temporary function in place of buffer functions to test _printf
 * @string: any string be buffered before writing to output
 * Return: Number of bytes copied to the buffer
 */
int output(char *string)
{
	/* Character index */
	int i;

	for (i = 0; string[i]; i++)
	{
		write(1, string + i, 1);
	}
	return (i);
}

/**
* _printf - manages sub-functions, returns number of bytes
* @format: the format to be executed on a string
* Return: number of bytes, output printed string
*/
int _printf(const char *format, ...)
{
	/* Make buffer */
	/*char buffer[1024];*/
/* Number of bytes printed */
	int byte_count = 0;
/* Iterator for format string */
	int x;
	va_list arguments;
/* A flag to tell the loop whether to interpret the following characters as part
 * of a format specification, or to send them directly to the buffer;
 * using a char because they're small and it only needs the value 0 or 1 */
	char parse_format_mode = 0;
/* Storage for the return value of get_function() so it can be used */
	/* char (*format_function) = NULL; */
/* formatted result of any format function */
	char *formatted_string;


	va_start(arguments, format);
	/* iterate over format string and search for format specifications */
	for (x = 0; format[x]; x++)
	{
		if (!parse_format_mode)
		{
			if (format[x] == '%')
			{
				/* '%' indicates a format specification; Activate format mode,
				 * then continue to the next char */
				parse_format_mode = 1;
				continue;
			}
			else 	/* for all other characters, output them */
			{
				/* output needs a pointer to a char, not the actual char */
				/* output(format + x); */
				write(1, format + x, 1);
			}
		}
		if (parse_format_mode)
		{
		/* Lookup and call format specifier interpreter func using get_function */
	        /* Whichever function gets called should return a formatted string */	       
			/* format_function = get_function(format[x]); */
			/* formatted_string = format_function(arguments); */
/* That string goes to the buffer to be printed */
			output(formatted_string);
		/* Formatting complete, deactivate format mode */
			parse_format_mode = 0;
		}
	}

	va_end(arguments);
	return (byte_count);
}
