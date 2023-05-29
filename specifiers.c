#include "main.h"

/**
 * get_specifier - finds format of a function
 * @s: string format
 * Return: the number of bytets
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int z = 0;

	while (specifiers[z].specifier)
	{
		if (*s == specifiers[z].specifier[0])
		{
			return (specifiers[z].f);
		}
		z++;
	}
	return (NULL);
}

/**
 * get_print_func - finds format of a fun
 * @s: string
 * @ap: argument
 * @params: parameters
 * Return: the number of bytes
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - finds func of a flag
 * @s: string
 * @params: parameters
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int z = 0;

	switch (*s)
	{
		case '+':
			z = params->plus_flag = 1;
			break;
		case ' ':
			z = params->space_flag = 1;
			break;
		case '#':
			z = params->hashtag_flag = 1;
			break;
		case '-':
			z = params->minus_flag = 1;
			break;
		case '0':
			z = params->zero_flag = 1;
			break;
	}
	return (z);
}

/**
 * get_modifier - get modifier func
 * @s: string
 * @params: parameters
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int z = 0;

	switch (*s)
	{
	case 'h':
		z = params->h_modifier = 1;
		break;
	case 'l':
		z = params->l_modifier = 1;
		break;
	}
	return (z);
}

/**
 * get_width - find the width in format string
 * @s: string
 * @params: parameters
 * @ap: argument
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int z = 0;

	if (*s == '*')
	{
		z = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			z = z * 10 + (*s++ - '0');
	}
	params->width = z;
	return (s);
}
