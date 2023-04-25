#ifndef _PRINTF_H
#define _PRINTF_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024
#define UNUSED(x)(void)(x)

/* DEFINING FLAGS */
#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASH_FLAG 8
#define SPACE_FLAG 16

/* DEFINING SIZES */
#define LONG_S 2
#define SHORT_S 1

/**
 * struct Formt - Struct op
 * @formt: The format.
 * @func: The function to which the format is associated.
 */
typedef struct Formt
{
	char formt;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct Formt frmt - format structure declaration.
 * @Formt: The formatted input.
 * @frmt: The function associated.
 */
typedef struct Formt frmt;

int handle_print(const char *formt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

int _printf(const char *format, ...);

/*All the functions used*/

/* printing characters and strings */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percentage(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* printing numbers */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_HEXA(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* printing non printable characters */

int print_un_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* printing memory address */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* handling specifiers 2 */

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Reversing a string */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*printing a string in rot 13*/

int print_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Handling width */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned(int is_negative, int ind,
char buffer[], int flags, int width, int precision, int size);

/* UTILS */

int is_printable(char);
int hexa_code_append(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /*_PRINTF_H*/
