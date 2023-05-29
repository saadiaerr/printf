#include "main.h"

/**
 * print_from_to - prints a range of char
 * @start: start
 * @stop: stop
 * @except: except
 * Return: number of bytes
 */
int print_from_to(char *start, char *stop, char *except)
{
	int tot = 0;

	while (start <= stop)
	{
		if (start != except)
			tot += _putchar(*start);
		start++;
	}
	return (tot);
}

/**
 * print_rev - string in reverse
 * @ap: string
 * @params: parameters
 * Return: number bytes
 */
int print_rev(va_list ap, params_t *params)
{
	int lentgh0, tot = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (lentgh0 = 0; *str; str++)
			lentgh0++;
		str--;
		for (; lentgh0 > 0; lentgh0--, str--)
			tot += _putchar(*str);
	}
	return (tot);
}

/**
 * print_rot13 - string in rot13
 * @ap: string
 * @params: parameters
 * Return: number of bytes
 */
int print_rot13(va_list ap, params_t *params)
{
	int s, index;
	int cnt = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	s = 0;
	index = 0;
	while (a[s])
	{
		if ((a[s] >= 'A' && a[s] <= 'Z')
		    || (a[s] >= 'a' && a[s] <= 'z'))
		{
			index = a[s] - 65;
			cnt += _putchar(arr[index]);
		}
		else
			cnt += _putchar(a[s]);
		s++;
	}
	return (cnt);
}
