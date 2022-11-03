#include "main.h"
/**
 * _putchar - is a function that writes the character c to the stdout.
 * @c: character to print
 *
 * Return: 1 is returned on success, -1 is given on error.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
