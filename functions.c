#include "main.h"
/**
 * print_char - a function that prints characters
 * @ap: va_list it holds all  arguments from the  main function
 * Return: number of characters printed
 */
int print_char(va_list ap)
{
	_putchar(va_arg(ap, int));
	return (1);
}
/**
 * print_str - prints the strings
 * @ap: va_list that holds all the arguments from main function
 * Return: number of characters printed
 */
int print_str(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i;

	if (str == NULL)
	{
		i = 6;
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
	}
	else
	{
		for (i = 0; str[i]; i++)
			_putchar(str[i]);
	}
	return (i);
}
/**
 * print_int - prints integers
 * @ap: va_list that holds all the  arguments from main function
 * Return: number of integers printed
 */
int print_int(va_list ap)
{
	int n;

	n = va_arg(ap, int);
	if (n < 0)
	{
		_putchar('-');
		return (print_unsigned_int(-n) + 1);
	}
	return (print_unsigned_int(n));
}
/**
 * _pow_recursion - returns value of x raised
 * to the power of y
 * @x: int
 * @y: int for power
 * Return: value of x^y
*/

int _pow_recursion(int x, int y)
{
	if (y == 0)
	{
		return (1);
	}
	if (y < 0)
	{
		return (-1);
	}
	else
		return (x * _pow_recursion(x, y - 1));
}
/**
 * print_unsigned_int - prints unsigned integers
 * @n: unsigned integers to print
 * Return: adds 1 in each recursion, adding up to the number of digits printed
 */
int print_unsigned_int(unsigned int n)
{
	int i;
	int len = 1;
	unsigned int n_cpy = (n / 10);

	while (n_cpy > 0)
	{
		len++;
		n_cpy = (n_cpy / 10);
	}
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(n / _pow_recursion(10, i) + '0');
		n = (n % _pow_recursion(10, i));
	}
	return (len);
}
