#include "main.h"

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
				counter +=len_str;
			}
			else
			{
				return (-1);
			}
		}
	format++;
	}
	va_end(arg_list);
	return (counter);
}
