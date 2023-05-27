#include "main.h"
void print_buffer(char b[], int *buff_ind);
/**
 * _printf - Print a function
 * @format: format of function
 * Return: Printed character
 */
int _printf(const char *format, ...)
{
	int j, pd = 0, pd_s = 0;
	int f, w, p, size, buff_ind = 0;
	va_list l;
	char b[BUFF_SIZE];

	if (!format)
		return (-1);

	va_start(l, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			b[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(b, &buff_ind);
			/* write(1, &format[j], 1);*/
			pd_s++;
		}
		else
		{
			print_buffer(b, &buff_ind);
			f = get_flags(format, &j);
			w = get_width(format, &j, l);
			p = get_precision(format, &j, l);
			size = get_size(format, &j);
			++j;
			pd = handle_print(format, &j, list, buffer,
				f, w, p, size);
			if (pd == -1)
				return (-1);
			pd_s += pd;
		}
	}

	print_buffer(b, &buff_ind);

	va_end(l);

	return (pd_s);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of characters
 * @buff_ind: Index
 */
void print_buffer(char b[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &b[0], *buff_ind);

	*buff_ind = 0;
}
