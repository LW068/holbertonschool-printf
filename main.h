#ifndef MAIN_H
#define MAIN_H

/* Headers */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

/* Documentation */

/**
 * struct format - a struct that holds va_list
 * @let: character
 * @func: pointer to a function
 *
 * Return: 0 success
*/

typedef struct format
{
	char *let;
	int (*func)(va_list ap);
} format_t;

/* Prototypes */

int _printf(const char *format, ...);
int map_func(va_list ap, char c);
int print_char(va_list ap);
int print_str(va_list ap);
int print_int(va_list ap);
int print_unsigned_int(unsigned int n);
int _putchar(char c);

#endif /* MAIN_H */
