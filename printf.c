#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int j, pd = 0, pd_s = 0;
	int fg, wth, pre, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[j], 1);*/
			pd_s++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			fg = get_flags(format, &j);
			wth = get_width(format, &j, list);
			pre = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			pd = handle_print(format, &j, list, buffer,
				fg, wth, pre, size);
			if (pd == -1)
				return (-1);
			pd_s += pd;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (pd_s);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
