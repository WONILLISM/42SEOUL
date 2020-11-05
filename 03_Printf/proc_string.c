/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:20:02 by wopark            #+#    #+#             */
/*   Updated: 2020/11/05 13:55:45 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_width(t_info *info, char *c_width, char *res)
{
	int	len;

	len = ft_strlen(res);
	if (info->width <= len)
		return (res);
	if (info->zero == 1 && info->precision == -1 && info->left == -1)
		info->padding = '0';
	if (!(c_width = set_container(info->width, info->padding)))
		return (NULL);
	if (info->left == 1)
		ft_memcpy(c_width, res, len);
	else
		ft_memcpy(&c_width[info->width - len], res, len);
	return (c_width);
}

static char	*process_precision(t_info *info, char *c_prec, char *res)
{
	int len;

	len = ft_strlen(res);
	if (info->precision == -1 || (info->precision != 0 && info->precision >= len))
		return (res);
	if (!(c_prec = malloc(sizeof(char) * info->precision + 1)))
		return (NULL);
	ft_memcpy(c_prec, res, info->precision);
	c_prec[info->precision] = '\0';
	return (c_prec);
}

static int	print_string(t_info *info, char *res)
{
	t_container	*container;
	int chk;

	chk = 0;
	if (!res)
	{
		res = ft_strdup("(null)");
		chk = 1;
	}
	container = init_container();
	if (!(res = process_precision(info, container->precision, res))
	|| !(res = process_width(info, container->width, res)))
	{
		free(container);
		return (_ERROR);
	}
	info->n += ft_putstr(res);
	free_container(container);
	if (chk)
		free(res);
	return (0);
}

int			process_string(va_list ap, t_info *info)
{
	char	*res;

	res = (char *)va_arg(ap, char *);
	return (print_string(info, res));
}
