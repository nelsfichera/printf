#include "holberton.h"
/**
* _strlen - gets the length of a string
* @string: target string
* Return: length of the string
*/
int _strlen(char *string)
{
	int x = 0;

	while (*(string + x))
		x++;
	return (x);
}
/**
* format_rot13 - encodes a string in ROT13
* @argument: target string
* Return: Encoded string
*/
char *format_rot13(va_list argument)
{
	int x = 0;
	char *string, *encoded_string;

	string = va_arg(argument, char *);

	encoded_string = malloc(sizeof(char) * (_strlen(string) + 1));

	if (encoded_string == NULL)
		return (NULL);

	while (string[x] != '\0')
	{
		if ((string[x] >= 'a' && string[x] <= 'm') || (string[x] >= 'A' && string[x] <= 'M'))
		{
			encoded_string[x] = string[x + 13];
		}
		else if ((string[x] >= 'n' && string[x] <= 'z') || (string[x] >= 'N' && string[x] <= 'Z'))
		{
			encoded_string[x] = string[x - 13];
		}
		else
			(encoded_string[x] = string[x]);
		x++;
	}
	encoded_string[x] = '\0';
	return (encoded_string);
}
/**
* format_char - prints a char arg
* @argument: the arg being passed
* Return: pointer to char
*/
char *format_char(va_list argument)
{
	char *c = malloc(sizeof(char) * 2);

	if (c == NULL)
		return (NULL);
	c[0] = va_arg(argument, int);
	c[1] = '\0';
	return (c);
}
/**
 * format_string - Prints an argument as a string
 * @argument: String argument
 * Return: Pointer to string
 */
char *format_string(va_list argument)
{
	int i;
	char *string = va_arg(argument, char *);
	char *new_string;

	if (string == NULL)
		return (NULL);
	new_string = malloc(_strlen(string) + 1);
	if (new_string == NULL)
		return (NULL);
	for (i = 0; string[i]; i++)
		new_string[i] = string[i];
	return (new_string);
}
#if 0
/**
* format_reverse - Prints an argument string in reverse
* @argument: the argument
* Return: pointer to string
*/
char *format_reverse(va_list argument)
{
	char *reverse;
	char *string;
	int x, n, length = 0;

	string = va_arg(list, char *);
	if (string == NULL)
		return (NULL);
	length = _strlen(str);

	reverse = malloc(sizeof(char) * (length + 1));
	if (reverse == NULL)
		return (NULL);

	for (n = (length - 1); n >= 0; n--)
		reverse[x++] = string[n];
	reverse[x] = '\0';
	return (reverse);
}
#endif
