#include "main.h"

/**
 * convert - converter function
 * @num: number
 * @base: base
 * @flags: flags
 * @params: paramater
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *str;
	unsigned long s = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		s = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';

	do	{
		*--str = array[s % base];
		s /= base;
	} while (s != 0);

	if (sign)
		*--str = sign;
	return (str);
}

/**
 * print_unsigned - prints unsigned integer number
 * @ap: argument of a pointer
 * @params: parameters
 * Return: bytes
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints an address of pointer
 * @ap: argument of a pointer
 * @params: the parameter
 * Return: bytes prin
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int s = va_arg(ap, unsigned long int);
	char *st;

	if (!s)
		return (_puts("(nil)"));

	st = convert(s, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--st = 's';
	*--st = '0';
	return (print_number(st, params));
}
