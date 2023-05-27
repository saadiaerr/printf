#include "main.h"

/**
 * print_unsigned - Prints unsigned num
 * @t: List
 * @b: Buffer array to print
 * @f: Calculates flags
 * @w: width
 * @p: Precision
 * @size: Size
 * Return: char printed.
 */
int print_unsigned(va_list t, char b[],
	int f, int w, int p, int size)
{
	int y = BUFF_SIZE - 2;
	unsigned long int n = va_arg(t, unsigned long int);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		b[y--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		b[y--] = (n % 10) + '0';
		n /= 10;
	}

	y++;

	return (write_unsgnd(0, y, b, f, w, p, size));
}

/************* NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints in octal
 * @t: List of arg
 * @b: Buffer array
 * @f:  Calculates flags
 * @w: width
 * @p: Precision
 * @size: Size
 * Return: char printed
 */
int print_octal(va_list t, char b[],
	int f, int w, int p, int size)
{

	int y = BUFF_SIZE - 2;
	unsigned long int n = va_arg(t, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(w);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		b[y--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		b[y--] = (n % 8) + '0';
		n /= 8;
	}

	if (f & F_HASH && init_n != 0)
		b[y--] = '0';

	y++;

	return (write_unsgnd(0, y, b, f, w, p, size));
}

/************** PRINT HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints hexadecimal
 * @t: List
 * @b: Buffer array
 * @f:  Calculates flags
 * @w: width
 * @p: Precision
 * @size: Size
 * Return:chars printed
 */
int print_hexadecimal(va_list t, char b[],
	int f, int w, int p, int size)
{
	return (print_hexa(t, "0123456789abcdef", b,
		f, 'x', w, p, size));
}

/************* PRINT iN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints in upper hexadecimal notation
 * @t: List
 * @b: Buffer array
 * @f:  Calculates flags
 * @w: width
 * @p: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list t, char b[],
	int f, int w, int p, int size)
{
	return (print_hexa(t, "0123456789ABCDEF", b,
		f, 'X', w, p, size));
}

/************** PRINT LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @t: List
 * @map_to: Array of values
 * @b: Buffer array to handle print
 * @f:  Calculates flags
 * @flag_char: Calculates flags
 * @w: width
 * @p: Precision
 * @size: Size
 * @size: Size specification
 * Return: chars printed
 */
int print_hexa(va_list t, char map_to[], char b[],
	int f, char flag_char, int w, int p, int size)
{
	int y = BUFF_SIZE - 2;
	unsigned long int n = va_arg(t, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(w);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		b[y--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		b[y--] = map_to[n % 16];
		n /= 16;
	}

	if (f & F_HASH && init_n != 0)
	{
		b[y--] = flag_char;
		b[y--] = '0';
	}

	y++;

	return (write_unsgnd(0, y, b, f, w, p, size));
}
