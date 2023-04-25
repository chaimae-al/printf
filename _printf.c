#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}


/**
 * _printf - produces output according to a format
 * @format: character string.
 * Return: the number of characters printed ( without NULL)
 */

int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int i, printed = 0, num_cs = 0, i_buff = 0;
	int flags, width, precision, size;

	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	i = 0;
while (format && format[i] != '\0')
{
	if (format[i] != '%')
	{
		buffer[i_buff++] = format[i];
		if (i_buff == BUFFER_SIZE)
			print_buffer(buffer, &i_buff);
		num_cs++;
	}
	else
	{
		print_buffer(buffer, &i_buff);
		flags = get_flags(format, &i);
		width = get_width(format, &i, list);
		precision = get_precision(format, &i, list);
		size = get_size(format, &i);
		++i;
		printed = handle_print(format, &i, list, buffer,
		flags, width, precision, size);
	if (printed == -1)
		return (-1);
	num_cs += printed;
	}

	i++;
}

	print_buffer(buffer, &i_buff);

	va_end(list);

	return (num_cs);
}
