#include "main.h"
/**
 * _puts - print a string
 * @str: string
 * Return: void
 */
int _puts(char *str)
{
	char *c = str;

	while (*str)
		_putchar(*str++);
	return (str - c);
}

/**
 * _putchar - writes the character
 * @c: character
 * Return: success 1, error, -1 is returned, and err no is set appropriately.
 */
int _putchar(int c)
{
	static int m;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || m >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}
