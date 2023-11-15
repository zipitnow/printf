#include "main.h"
/**
 *string_print - a function that produces output
 *_printf - function to print strings
 *@str: character string
 *according to a format
 *Return: -1 as fail and 0 as success
 */


int string_print(char *str)
{
	int len_str = 0;

	while (str[len_str] != '\0')
		len_str++;
	write(1, str, len_str);
	return (len_str);
}

int _printf(const char *format, ...)
{
	char c;
	char *str;
	int counter = 0;
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
				str = va_arg(arg_list, char*);
				counter += string_print(str);
			}
		}
	format++;
	}
	va_end(arg_list);
	return (counter);
}
