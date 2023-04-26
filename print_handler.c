#include "main.h"

/**
 * handle_print - a function that prints an argument based on its type
 * @formt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: index
 * @buffer: Buffer array to the function
 * @flags: get active flags
 * @width: get width
 * @precision:  specifies precision
 * @size: specifies size
 * Return: 1 or 2;
 */

int handle_print(const char *formt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, x_len = 0, printed_chars = -1;
	frmt formt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percentage},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsgnd}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_HEXA}, {'p', print_pointer}, {'S', print_un_printable},
		{'r', print_reverse}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (i = 0; formt_types[i].formt != '\0'; i++)
		if (formt[*ind] == formt_types[i].formt)
			return (formt_types[i].func(list, buffer, flags, width, precision, size));

	if (formt_types[i].formt == '\0')
	{
		if (formt[*ind] == '\0')
			return (-1);
		x_len += write(1, "%%", 1);
		if (formt[*ind - 1] == ' ')
			x_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (formt[*ind] != ' ' && formt[*ind] != '%')
				--(*ind);
			if (formt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		x_len += write(1, &formt[*ind], 1);
		return (x_len);
	}
	return (printed_chars);
}
