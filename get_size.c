#include "main.h"

/**
 * get_size - a function calculating the size to cast the argument
 * @format: Formatted input
 * @i: List of arguments to be printed.
 *
 * Return: The precision.
 */
int get_size(const char *format, int *i)
{
	int current_i = *i + 1;
	int size = 0;

	if (format[current_i] == 'l')
		size = LONG_S;
	else if (format[current_i] == 'h')
		size = SHORT_S;

	if (size == 0)
		*i = current_i - 1;
	else
		*i = current_i;

	return (size);
}
