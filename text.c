#include "holberton.h"
#if 0
/**
* format_rot13 - encodes a string in ROT13
* @string: target string
* Return: Encoded string
*/
int format_rot13(va_list string)
{
	int x = 0, i = 0, length = 0; /*for iteration and return value*/
	char abc[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	char rotabc[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};
	char *str, *encoded_str; /*for copying and encoding*/

	str = va_arg(string, char *);

	for (x = 0; string[x] != '\0'; x++)
		length++;

	encoded_str = malloc(sizeof(char) * length + 1);

	if (!encoded_str)
		return ('\0');
	for (x = 0; x <= length; x++)
		encoded_str[x] = str[x];
	for (x = 0; encoded_str[x] != '\0'; x++)
	{
		for (i = 0; abc[i] != '\0'; i++)
		{
			if (str[x] == abc[i])
			{
				encoded_str[x] = rotabc[i];
				break;
			}
		}
	}
	for (x = 0; encoded_str[x]; x++)
		write(1, &encoded_str[x], 1);
	free(encoded_str);
	return (length);
}
#endif	/* temporary exclusion of ROT13 */
/**
 * format_string - Prints an argument as a string
 * @string: String argument
 * Return: Pointer to string
 */
char *format_string(va_list argument)
{
	char *string = va_arg(argument, char *);
	return (string);
}
