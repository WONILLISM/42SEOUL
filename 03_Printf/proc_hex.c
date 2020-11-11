/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:58:36 by wopark            #+#    #+#             */
/*   Updated: 2020/11/11 13:37:14 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_hash(t_info *info, char *c_width, char c, int len)
{
	char hash[3];

	hash[0] = '0';
	hash[1] = c;
	hash[2] = '\0';
	if (info->left == 1 || info->zero == 1)
		ft_memcpy(c_width, hash, 2);
	else
		ft_memcpy(&c_width[info->width - len - 2], hash, 2);
}

static char	*process_width(t_info *info, char *c_width, char *res, char c)
{
	int	len;

	len = ft_strlen(res);
	if (info->width <= len && info->hash == 0)
		return (res);
	else if (info->width < len + info->hash)
		info->width = len + info->hash;
	// printf("----- %d - %d ----\n", info->zero, info->precision);
	if (info->left != 1 && info->zero == 1 && info->precision == -1)
		info->padding = '0';
	if (!(c_width = set_container(info->width,info->padding)))
		return (NULL);
	if (info->hash == 2)
		process_hash(info, c_width, c, len);
	if (info->left == 1)
		ft_memcpy(&c_width[info->hash], res, len);
	else
		ft_memcpy(&c_width[info->width - len], res, len);
	return (c_width);
}

static char	*process_precision(t_info *info, char *c_prec, char *res)
{
	int		len;

	len = ft_strlen(res);
	if (info->precision >= 0)
		info->zero = -1;
	if (res[0] == '0')
		info->hash = 0;
	if (res[0] == '0' && info->precision == 0)
		return ("");
	if (info->precision <= len)
		return (res);
	if (!(c_prec = set_container(info->precision, '0')))
		return (NULL);
	ft_memcpy(&c_prec[info->precision - len], res, ft_strlen(res));
	return (c_prec);
}

static int	print_hex(t_info *info, char *res, char c)
{
	t_container *container;

	container = init_container();
	if (!(res = process_precision(info, container->precision, res))
	|| !(res = process_width(info, container->width, res, c)))
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
	return (print_hex(info, res, c));
}
