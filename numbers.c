#include "holberton.h"
#if 0
/**
* format_binary - changes an int to binary
* @argument: the integer to change
* Return: binaried string
*/
char *format_binary(va_list argument)
{
	int x = 0, i = 0, n = 0;
	int split = 1;
	char *binary;

	n = va_arg(argument, int);
	i = n;
	/*malloc up to max binary int*/
	binary = malloc(sizeof(char) * 33);
	if (binary == NULL)
		return (NULL);
	/*negative numbers*/
	if (n < 0)
	{
		binary[0] = 1 + '0';
		x++;
		n *= -1;
		i *= -1;
	}
	/*split and convert*/
	while (n > 1)
	{
		n /= 2;
		split *= 2;
	}
	while (split > 0)
	{
		binary[x++] = (i / split + '0');
		i %= split;
		split /= 2;
	}
	binary[x] = '\0';
	return (binary);
}
/**
* format_octal - formats into octal notation
* @argument: the integer to convert
* Return: octaled string
*/
char *format_octal(va_list argument)
{
	int x = 0, i = 0, n = 0;
	int split = 1;
	char *octal;

	n = va_arg(argument, int);
	i = n;
	/*malloc up to max octal int*/
	octal = malloc(sizeof(char) * 12);
	if (octal == NULL)
		return (NULL);
	/*negatives*/
	if (n < 0)
	{
		octal[0] = 1 + '0';
		x++;
		n *= -1;
		i *= -1;
	}
	/*split and convert*/
	while (k > 1)
	{
		k /= 8;
		split *= 8;
	}
	while (split > 0)
	{
		octal[x++] = (i / split + '0');
		i %= split;
		split /= 8;
	}
	octal[x] = '\0';
	return (octal);
}
#endif
/**
 * format_decimal - converts an int to a string
 * @argument: pointer to va_list arg which will be interpreted as an int
 * Return: string format integer
 */
char *format_decimal(va_list argument)
{
	int integer = va_arg(argument, int);
	int digits, temp = integer;
	int limit = 0;
	char *formatted;

	for (digits = 0; temp != 0; digits++)
		temp /= 10;

	if (integer <= 0)
		digits++;	/* Negative sign or count zero as one digit */

	formatted = malloc(digits + 1); /* +1 for Null byte */
	if (!formatted)
		return (NULL);

	formatted[digits--] = '\0'; /* Set null byte at the end of the string */
	if (integer < 0)
	{
		formatted[0] = '-'; /* Negative sign at the beginning */
		limit = 1;
	}
	for (; digits >= limit; digits--)
	{
		temp = integer % 10;
		formatted[digits] = temp < 0 ? -temp + '0' : temp + '0';
		integer /= 10;
	}
	return (formatted);
}
