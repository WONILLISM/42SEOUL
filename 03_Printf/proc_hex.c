#include "ft_printf.h"

static char	*process_width(t_info *info, char *c_width, char *res)
{
	int	len;

	len = ft_strlen(res);
	if (info->sign == '\0' && info->width < len)
		return (res);
	if (info->zero == 1 && info->precision == -1 && info->left == -1)
		info->padding = '0';
	if (info->width < len)
		info->width = len;
	if (info->sign && info->width == len)
		(info->width)++;
	if (!(c_width = set_container(info->width, info->padding)))
		return (NULL);
	if (info->left == 1 && info->sign)
		ft_memcpy(c_width + 1, res, len);
	else if (info->left == 1)
		ft_memcpy(c_width, res, len);
	else
		ft_memcpy(&c_width[info->width - len], res, len + 1);
	return (proc_sign(info, c_width, len));
}

static char	*process_precision(t_info *info, char *c_prec, char *res)
{
	int	len;

	len = ft_strlen(res);
	if (res[0] == '0' && info->precision == 0)
		res = "";
	if (info->precision <= len)
		return (res);
	if (!(c_prec = set_container(info->precision, '0')))
		return (NULL);
	ft_memcpy(&c_prec[info->precision - len], res, ft_strlen(res));
	return (c_prec);
}

static int	print_hex(t_info *info, char *res)
{
	t_container *container;

	container = init_container();
	if (!(res = process_precision(info, container->precision, res))
	|| !(res = process_width(info, container->width, res)))
	{
		free(container);
		return (_ERROR);
	}
	info->n += ft_putstr(res);
	free_container(container);
	return (0);
}

int			process_hex(va_list ap, t_info *info, char c)
{
	char	*res;
	char	*base;

	if (c == 'x')
		base = LOWER_HEX;
	else if (c == 'X')
		base = UPPER_HEX;

	res = ft_itoa_base((unsigned int)va_arg(ap, unsigned int), base);
	return (print_hex(info, res));
}
