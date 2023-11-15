#include "main.h"
/**
 * _printf - a function that produces output
 *according to a format
 *@format: character string
 *Return: -1 as fail and 0 as success
 */

int _printf(const char *format, ...)
{
	int counter = 0;
	char c;
	char *str;
	int len_str;
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			counter++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			else if (*format == '%')
			{
				write(1, format, 1);
				counter++;
			}
			else if (*format == 'c')
			{
				c = va_arg(arg_list, int);
				write(1, &c, 1);
				counter++;
			}
			else if (*format == 's')
			{
				len_str = 0;
				str = va_arg(arg_list, char*);
				while (str[len_str] != '\0')
					len_str++;
				write(1, str, len_str);
				counter += len_str;
			}
		}
	format++;
	}
	va_end(arg_list);
	return (counter);
}
