#include "ft_printf.h"


int	printf_parer(const char *format, va_list ap)
{
	while (*format)
	{
		if (*format == '%')
		{

		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = printf_parser(format, ap);
	va_end(ap);
	return (ret);
}
