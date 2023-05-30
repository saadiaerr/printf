#include "main.h"

/**
 * print_char - print characters
 * @ap: argument
 * @params: parameters
 * Return: number chars
 */
int print_char(va_list ap, params_t *params)
{
	char pd_char = ' ';
	unsigned int pd = 1, tot = 0, c = va_arg(ap, int);

	if (params->minus_flag)
		tot += _putchar(c);
	while (pd++ < params->width)
		tot += _putchar(pd_char);
	if (!params->minus_flag)
		tot += _putchar(c);
	return (tot);
}

/**
 * print_int - prints int
 * @ap: argument
 * @params: parameters
 * Return: number chars
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ap: argument
 * @params: parameters
 * Return: number of chars
 */
int print_string(va_list ap, params_t *params)
{
	char *st = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, tot = 0, z = 0, s;

	(void)params;
	switch ((int)(!st))
		case 1:
			st = NULL_STRING;

	s = pad = _strlen(st);
	if (params->precision < pad)
		s = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (z = 0; z < pad; z++)
				tot += _putchar(*st++);
		else
			tot += _puts(st);
	}
	while (s++ < params->width)
		tot += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (z = 0; z < pad; z++)
				tot += _putchar(*st++);
		else
			tot += _puts(st);
	}
	return (tot);
}

/**
 * print_percent - prints string
 * @ap: argument
 * @params: parameters
 * Return: number chara
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: parameters
 * Return: number chara
 */
int print_S(va_list ap, params_t *params)
{
	char *st = va_arg(ap, char *);
	char *hex;
	int tot = 0;

	if ((int)(!st))
		return (_puts(NULL_STRING));
	for (; *st; st++)
	{
		if ((*st > 0 && *st < 32) || *st >= 127)
		{
			tot += _putchar('\\');
			tot += _putchar('x');
			hex = convert(*st, 16, 0, params);
			if (!hex[1])
				tot += _putchar('0');
			tot += _puts(hex);
		}
		else
		{
			tot += _putchar(*st);
		}
	}
	return (tot);
}
