#include "main.h"

int _printf(const char *format, ...)
{
	int counter = 0;

	va_list arg_list;
	va_start(arg_list, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			char *str1 = va_arg(arg_list, int);
			len_str1 = 0;
			while (str1[len_str1] != '\0')
				len_str1++;
			write(1, str1, len_str1);
			counter++;
		}
		else
		{
			format++;

			if (*format == '%')
			{
				write(1, format, 1);
				counter++;
				break;
			}
			
			if (*format == 'c')
			{
				char c = va_arg(arg_list, int);
				write(1, c, 1);
				counter++;
			}

			if (*format == 's')
			{
				len_str2 = 0;
				char *str2 = va_arg(arg_list, int);
				while (str2[len_str2] != '\0')
					len_str2++;

				write(1, str2, len_str2);
				counter++;
			}
		}
	format++;
	}
	va_end(arg);
	return (counter++);
}
