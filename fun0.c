#include "main.h"

/**
 * print_char - Prints a char
 * @t: List a of arguments
 * @b: Buffer
 * @f: flags
 * @w: Width
 * @p: Precision
 * @size: Size
 * Return: num of character
 */
int print_char(va_list t, char b[], int f, int w, int p, int size)
{
	char char1 = va_arg(t, int);

	return (handle_write_char(char1, b, f, w, p, size));
}

/**
 * print_string - Prints a string
 * @t: List
 * @b: Buffer
 * @f: flags
 * @w: width.
 * @p: Precision
 * @size: Size
 * Return: Number of character
 */
int print_string(va_list t, char b[], int f, int w, int p, int size)
{
	int len = 0;
	int y;
	char *s = va_arg(t, char *);

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(size);
	if (!s)
	{
		s = "(null)";
		if (p >= 6)
			s = "      ";
	}

	while (s[len] != '\0')
		len++;

	if (p >= 0 && p < len)
		len = p;

	if (w > len)
	{
		if (f & F_MINUS)
		{
			write(1, &s[0], len);
			for (y = w - len; y > 0; y--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (y = w - len; y > 0; y--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (w);
		}
	}
	return (write(1, s, len));
}


/**
 * print_percent - Print percent sign
 * @t: List
 * @b: array Buffer
 * @f: flags
 * @w: width
 * @p: Precision
 * @size: Size of character
 * Return: Number of chars
 */
int print_percent(va_list t, char b[], int f, int w, int p, int size)
{
	UNUSED(t);
	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print integre
 * @t: List
 * @b: Buffer array
 * @f: flags
 * @w: width
 * @p: Precision
 * @size: Size of character
 * Return: Number of chars
 */
int print_int(va_list t, char b[],
	int f, int w, int p, int size)
{
	int y = BUFF_SIZE - 2;
	int nega = 0;
	long int m = va_arg(t, long int);
	unsigned long int nu;

	m = convert_size_number(m, size);

	if (m == 0)
		b[y--] = '0';

	b[BUFF_SIZE - 1] = '\0';
	nu = (unsigned long int)m;

	if (m < 0)
	{
		nu = (unsigned long int)((-1) * m);
		nega = 1;
	}

	while (nu > 0)
	{
		b[y--] = (nu % 10) + '0';
		nu /= 10;
	}

	y++;

	return (write_number(nega, y, b, f, w, p, size));
}
