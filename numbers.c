#include "holberton.h"
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
