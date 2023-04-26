#include "main.h"

/**
 * is_printable - a function that testes  if a char is printable
 * @c: Char to be tested
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hexa_code_append - a function that appends ascci
 * in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: index that scarts the appending
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int hexa_code_append(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - a function that  verifies if a char is a digit
 * @c: Char to be tested
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - a function that convers
 * a number to the specified size
 * @num: Number to be converted
 * @size: Number indicating the type to be casted
 * Return: the value of the casted number
 */
long int convert_size_number(long int num, int size)
{
	if (size == LONG_S)
		return (num);
	else if (size == SHORT_S)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd -  a function that converts
 * a number to the specified size
 * @num: Number to be converted
 * @size: Number indicating the type to be casted
 * Return: the value of the  converted number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == LONG_S)
		return (num);
	else if (size == SHORT_S)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
