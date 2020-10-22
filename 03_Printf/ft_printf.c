#include "ft_printf.h"

int	printf_parser(const char *format, va_list ap)
{
	t_info	info;
	char	tmp;

	info.n = 0;
	while (*format)
	{
		while (*format != '%' && *format)
		{
			info.n += 1;
			ft_putchar_fd(*format, 1);
			format += 1;
		}
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
