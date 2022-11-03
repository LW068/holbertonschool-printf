#include "main.h"
#include <stdarg.h>

/**
 *_printf - produces the output according to formatting.
 *@format: Input string with format char
 *
 * Return: Count of Characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int charSum = 0, index = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[index] != '\0')
	{
		if (format[index] != '%')
		{
			charSum += printChar(format[index++]);
			continue;
		}
		index++;
		skipFlags(&index, format);
		switch (format[index])
		{
		case 'c':
			charSum += printChar(va_arg(args, int));
			break;
		case 's':
			charSum += printString(va_arg(args, char *));
			break;
		case '%':
			charSum += printChar('%');
			break;
		case 'd':
		case 'i':
			charSum += printInt(va_arg(args, int));
			break;
		case '\0':
			return (-1);
		default:
			charSum += printChar('%');
			charSum += printChar(format[index]);
		} /* Increment index past the format char */
		index++;
	}
	va_end(args);
	return (charSum);
}
