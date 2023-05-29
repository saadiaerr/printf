/************** print unsigned hexa in lowercase **************/

#include "main.h"

/**
 * print_hex - prints unsigned hexadicimal in lowercase
 * @ap: the argument pointer
 * @params: the parameters
 * Return: bytes
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long j;
	int i = 0;
	char *c;

	if (params->l_modifier)
		j = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		j = (unsigned short int)va_arg(ap, unsigned int);
	else
		j = (unsigned int)va_arg(ap, unsigned int);

	c = convert(j, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && j)
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
	unsigned long j;
	int i = 0;
	char *c;

	if (params->l_modifier)
		j = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		j = (unsigned short int)va_arg(ap, unsigned int);
	else
		j = (unsigned int)va_arg(ap, unsigned int);

	c = convert(j, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && j)
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
	unsigned long j;
	char *jh;
	int s = 0;

	if (params->l_modifier)
		j = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		j = (unsigned short int)va_arg(ap, unsigned int);
	else
		j = (unsigned int)va_arg(ap, unsigned int);
	jh = convert(j, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && j)
		*--jh = '0';
	params->unsign = 1;
	return (s += print_number(jh, params));
}
