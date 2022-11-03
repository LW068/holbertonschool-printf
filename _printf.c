#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - outputs according to formatting.
 *
 * @format: a string of characters.
 * Return: NULL
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, charCount = 0;

	if (format == NULL || (format[i] == '%' && !format[i + 1]))
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 0 || format[i + 1] == '%'))
		{
			_putchar('%');
			i++;
			charCount++;
		}
		else if (format[i] == '%')
		{
			charCount += map_func(ap, format[i + 1]);
			i++;
		}
		else
		{
			charCount += 1;
			_putchar(format[i]);
		}
	}
	va_end(ap);
	return (charCount);
}
/**
 * map_func - maps format specifiers to functions
 * @ap: va_list that contains args
 * @c: char (format i + 1)
 * Return: 2 (number of characters printed)
 */
int map_func(va_list ap, char c)
{
	int j;
	format_t f[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int}
	};
	for (j = 0; j < 4; j++)
		if (*f[j].let == c)
			return (f[j].func(ap));
	_putchar('%');
	_putchar(c);
	return (2);
}
