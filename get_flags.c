#include "main.h"

/**
 * get_flags - a function that calculate active flags
 * @format: Formatted inputs
 * @i: parameter taker.
 * Return: active Flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, current_i;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {MINUS_FLAG, PLUS_FLAG, ZERO_FLAG, HASH_FLAG,
		SPACE_FLAG, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
			if (format[current_i] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CHAR[j] == 0)
			break;
	}

	*i = current_i - 1;

	return (flags);
}
