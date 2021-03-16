#include "holberton.h"

/**
* get_function - get the appropriate function
* @n: identifier for function
* Return: Pointer to a string formatting function
*/
char *(*get_function(char n))(va_list)
{
	int x  = 0;
	func_t func_table[] = {
		{'c', format_char},
		{'s', format_string},
		{'%', format_percent},
		{'d', format_decimal},
		{'i', format_decimal},
		{'b', format_binary},
		{'R', format_rot13},
		{'r', format_reverse},
		{'o', format_octal},
		{'u', format_unsigned},
		/* {'x', format_hex}, */
		/* {'X', format_hex}, */
		{'\0', NULL}
	};
	while (func_table[x].type != '\0')
	{
		if (func_table[x].type == n)
			return (func_table[x].function);
		x++;
	}
	return (NULL);
}
/**
 * output - a temporary function in place of buffer functions to test _printf
 * @string: any string to be buffered before writing to output
 * @buffer: buffer destination
 * @buffer_size: size of the buffer
 * @start: where to start writing to the buffer
 * @char_mode: for copying single chars (used to force copy a null byte)
 * Return: Number of bytes copied to the buffer
 */
int output(char *string, char *buffer, int buffer_size,
	   int start, int char_mode)
{
	int bi = start;
	int si = 0;

	if (char_mode)
	{
		buffer[bi % buffer_size] = string[si];
			if (++bi % buffer_size == 0)
				write(1, buffer, buffer_size);
	}
	else
	{
		for (; string[si]; si++)
		{
			buffer[bi % buffer_size] = string[si];
			if (++bi % buffer_size == 0)
				write(1, buffer, buffer_size);
		}
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
	char buffer[1024];
	int x, format_mode_index, byte_count = 0;
	va_list arguments;
	char parse_format_mode = 0;
	char *(*format_function)(va_list) = NULL;
	char *formatted_string;
	char char_to_string[2];

	if (!format)
		return (-1);
	char_to_string[1] = '\0';
	va_start(arguments, format);
	for (x = 0; format[x]; x++)
	{
		if (!parse_format_mode)
		{
			if (format[x] == '%')
			{
				parse_format_mode = 1;
				format_mode_index = x;
				continue;
			}
			else
			{
				char_to_string[0] = format[x];
				byte_count += output(char_to_string, buffer, 1024, byte_count, 1);
			}
		}
		if (parse_format_mode)
		{
			format_function = get_function(format[x]);
			if (!format_function)
			{
				byte_count += output("%", buffer, 1024,
						     byte_count, 0);
				x = format_mode_index;
			}
			else
			{
				formatted_string = format_function(arguments);
				if (!formatted_string)
					byte_count += output("(null)", buffer, 1024, byte_count, 0);
				else
				{
					byte_count += output(formatted_string,
			     buffer, 1024, byte_count, format[x] == 'c');
					free(formatted_string);
				}
			}
			parse_format_mode = 0;
		}
	}
	write(1, buffer, byte_count % 1024);
	va_end(arguments);
	return (byte_count);
}
