#include "holberton.h"

/*PUT IN _PRINTF.C*/ 

/**
* get_function - get the function
* @n: identifier for function
* Return: function pointer
*/
char *(*get_function(char n))(va_list)
{
	int x = 0;
		
	/*merge below with _printf.c*/ 
	print options[] = {
		{'c',}
		{'s',}
		{'%',}
		{'d',}
		{'i',}
	};
	while (options[x].type != '\0')
	{
		if(options[x].types == n)
			return (options[x].function);
		x++;
	}
	return (NULL);
}
/**
* make_buffer: create a buffer to hold a string until ready for printing 
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
	write(1, buffer, len);
	/*free, deinitialize*/
	free(buffer); 
	va_end(arguments);
}
