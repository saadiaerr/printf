#include "main.h"

/**
 * _isdigit - checks digit
 * @c: the character to check
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string to check
 * Return: integer length
 */
int _strlen(char *s)
{
	int z = 0;

	while (*s++)
		z++;
	return (z);
}

/**
 * print_number - prints a number
 * @str: string
 * @params: parameter
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int y = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		y--;
	}
	if (params->precision != UINT_MAX)
		while (y++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number
 * @str: string
 * @params: parameter
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int s = 0, neg, neg2, z = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && s < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		z++;
	if (neg && pad_char == '0')
		s += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		s += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		s += _putchar(' ');
	while (z++ < params->width)
		s += _putchar(pad_char);
	if (neg && pad_char == ' ')
		s += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		s += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		s += _putchar(' ');
	s += _puts(str);
	return (s);
}

/**
 * print_number_left_shift - prints a number
 * @str: string
 * @params: parameter
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int s = 0, neg, neg2, z = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && s < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		s += _putchar('+'), z++;
	else if (params->space_flag && !neg2 && !params->unsign)
		s += _putchar(' '), z++;
	s += _puts(str);
	while (z++ < params->width)
		s += _putchar(pad_char);
	return (s);
}
