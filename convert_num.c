/************** print unsigned hexa in lowercase **************/

#include "main.h"

/**
 * print_hex - prints unsigned hexadicimal in lowercasee
 * @ap: the argument pointer
 * @params: the parameters
 * Return: bytes
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long l;
	int i = 0;
	char *c;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	c = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--c = 'i';
		*--c = '0';
	}
	params->unsign = 1;
	return (i += print_number(c, params));
}

/************** PRINT HEXX NUM IN uppercase **************/
/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long l;
	int i = 0;
	char *c;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	c = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--c = 'I';
		*--c = '0';
	}
	params->unsign = 1;
	return (i += print_number(c, params));
}
/************** print unsigned binary **************/
/**
 * print_binary - prints unsigned binary
 * @ap: argument
 * @params: parameters struct
 * Return: bytes
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int m = va_arg(ap, unsigned int);
	char *c = convert(m, 2, CONVERT_UNSIGNED, params);
	int s = 0;

	if (params->hashtag_flag && m)
		*--c = '0';
	params->unsign = 1;
	return (s += print_number(c, params));
}
/************** PRINT unsigned octal **************/
/**
 * print_octal - prints unsigned octal
 * @ap: the argument
 * @params: the parameters struct
 * Return: bytes
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	char *jh;
	int s = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	jh = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--jh = '0';
	params->unsign = 1;
	return (s += print_number(jh, params));
}
