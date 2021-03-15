#include "holberton.h"

/**
* get_function - get the appropriate function
* @n: identifier                 for function
* Return: Pointer to a string formatting function
*/
char *(*get_function(char n))(va_list)
{
	int x  = 0; /*for iteration*/
	func_t func_table[] = {
		{'c', format_char},
		{'s', format_string},
		{'%', format_percent},
		{'d', format_decimal},
		{'i', format_decimal},
		/* {'b', format_binary}, */
		/* {'R', format_rot13}, */
		/* {'o', format_octal}, */
		{'\0', NULL}
	};
	while (func_table[x].type != '\0')
	{
		if (func_table[x].type == n)
			return(func_table[x].function);
		x++;
	}
	return (NULL);
}

/**
 * output - a temporary function in place of buffer functions to test _printf
 * @string: any string to be buffered before writing to output
 * Return: Number of bytes copied to the buffer
 */
int output(char *string, char *buffer, int buffer_size, int start)
{
	/* Indecies */
	int bi = start; /* Starting index */
	int si = 0;

	for (; string[si]; si++)
	{
		buffer[bi % buffer_size] = string[si];
			if (++bi % buffer_size == 0) /* When full */
				write(1, buffer, buffer_size); /* Empty buffer */
	}
	return (bi - start);
}

/**
* _printf - manages sub-functions, returns number of bytes
* @format: the format to be executed on a string
* Return: number of bytes, output printed string
*/
int _printf(const char *format, ...)
{
	/* Make buffer */
	char buffer[1024];
/* Number of bytes printed */
	int byte_count = 0;
/* Iterator for format string */
	int x;
	va_list arguments;
/* A flag to tell the loop whether to interpret the following characters as part
 * of a format specification, or to send them directly to the buffer;
 * using a char because they're small and it only needs the value 0 or 1 */
	char parse_format_mode = 0;
/* Storage for the return value of get_function() so it can be called */
	char *(*format_function)(va_list) = NULL;
/* formatted result of any format function */
	char *formatted_string;
	/* Storage to convert a char to a string */
	char *char_to_string = malloc(2);

	char_to_string[1] = '\0';
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
				/* but output needs a string, not the actual char */
				*char_to_string = format[x];
				byte_count += output(char_to_string, buffer, 1024, byte_count);
			}
		}
		if (parse_format_mode)
		{
		/* Lookup and call format specifier interpreter func using get_function */
	        /* Whichever function gets called should return a formatted string */
			format_function = get_function(format[x]);
			if (!format_function)
			{	/* No matching function was found; print %[char] */
				*char_to_string = format[x];
				byte_count += output("%", buffer, 1024, byte_count);
				byte_count += output(char_to_string, buffer, 1024, byte_count);
			}
			else
			{
				formatted_string = format_function(arguments);

				/* if (!formatted_string) */
				/* What to do if NULL???? */
/* That string goes to the buffer to be printed */
				byte_count += output(formatted_string, buffer, 1024, byte_count);
				free(formatted_string);
				/* Formatting complete, deactivate format mode */
			}
			parse_format_mode = 0;
		}
	}

	/* Empty the buffer */
	write(1, buffer, byte_count % 1024);

	va_end(arguments);
	return (byte_count);
}
