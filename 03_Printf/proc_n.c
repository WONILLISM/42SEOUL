#include "ft_printf.h"

int			process_n(va_list ap, t_info *info)
{
	int	*res;

	res = va_arg(ap, int *);
	*res = info->n;
	return (0);
}
