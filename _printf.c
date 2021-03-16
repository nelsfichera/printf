#include "holberton.h"

/**
* get_function - get the appropriate function
* @n: identifier for function
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
		{'b', format_binary},
		{'R', format_rot13},
		{'o', format_octal},
		{'u', format_unsigned},
		{'x', format_hex},
		{'X', format_hex},
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
#if 0
/**
* get_flag - get the appropriate function for handling flags
* @flag: flag identifier
* Return: Pointer to a string formatting function
*/
char *(*get_flag(char flag))(va_list)
{
	int x = 0; /*for iteration*/
	func_t func_table[] = {
		{'-', format_minus},
		{'+', format_plus},
		{'0', format_zero},
		{' ', format_space},
		{'#', format_hash},
		{'\0', NULL}
	};
	while (func_table[x].type != '\0')
	{
		if (func_table[x].type == flag)
			return(func_table[x].function);
		x++;
	}
	return (NULL);
}
#endif	/* Ignore flag function table */
/**
 * output - a temporary function in place of buffer functions to test _printf
 * @string: any string to be buffered before writing to output
 * @buffer: buffer destination (needs to be passed in to persist after call ends)
 * @buffer_size: size of the buffer
 * @start: where to start writing to the buffer
 * @char_mode: for copying single chars (used to force copy a null byte)
 * Return: Number of bytes copied to the buffer
 */
int output(char *string, char *buffer, int buffer_size, int start, int char_mode)
{
	/* Indecies */
	int bi = start; /* Starting index */
	int si = 0;

	if (char_mode)
	{
		buffer[bi % buffer_size] = string[si];
			if (++bi % buffer_size == 0) /* When full */
				write(1, buffer, buffer_size); /* Print entire buffer */
	}
	else
	{
		for (; string[si]; si++)
		{
			buffer[bi % buffer_size] = string[si];
			if (++bi % buffer_size == 0) /* When full */
				write(1, buffer, buffer_size); /* Print entire buffer */
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
	/* Make buffer */
	char buffer[1024];
/* Number of bytes printed */
	int byte_count = 0;
/* Iterator for format string; index when format mode was entered - needed if invalid format */
	int x, format_mode_index;
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
	char char_to_string[2];

	if (!format)
		return (-1);
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
				format_mode_index = x; /* Index of % in case format is invalid */
				continue;
			}
			else 	/* for all other characters, output them */
			{
				/* but output needs a string, not the actual char */
				char_to_string[0] = format[x];
				byte_count += output(char_to_string, buffer, 1024, byte_count, 1);
			}
		}
		if (parse_format_mode)
		{
		/* Lookup and call format specifier interpreter func using get_function */
	        /* Whichever function gets called should return a formatted string */
			format_function = get_function(format[x]);
			if (!format_function)
			{	/* No matching function was found; print % and return to index after % was encountered */
				byte_count += output("%", buffer, 1024, byte_count, 0);
				x = format_mode_index; /* Go back to the % (x will increment when loop ends and continue from the index following the %) */
			}
			else
			{
				formatted_string = format_function(arguments);
				if (!formatted_string) /* If the function returned NULL, print (null) */
					byte_count += output("(null)", buffer, 1024, byte_count, 0);
				else
				{/* That string goes to the buffer to be printed */
					byte_count += output(formatted_string,\
buffer, 1024, byte_count, format[x] == 'c');
					free(formatted_string);
				}
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
