#include "main.h"

/**
 * get_precision - find the precision in format string
 * @p: string form
 * @params: parameters
 * @ap: argument
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int z = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		z = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			z = z * 10 + (*p++ - '0');
	}
	params->precision = z;
	return (p);
}
