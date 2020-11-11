/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:45:35 by wopark            #+#    #+#             */
/*   Updated: 2020/11/11 15:05:24 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_width(t_info *info, char *c_width)
{
	info->width--;
	if (info->width < 0)
		return ("");
	if (info->zero == 1 && info->left == -1)
		info->padding = '0';
	if (!(c_width = set_container(info->width, info->padding)))
		return (NULL);
	return (c_width);
}

static int	print_percent(t_info *info, char c)
{
	t_container *container;
	char		*res;

	container = init_container();
	if (!(res = process_width(info, container->width)))
	{
		free(container);
		return (_ERROR);
	}
	if (info->left == 1)
		info->n += ft_putchar(c) + ft_putstr(res);
	else
		info->n += ft_putstr(res) + ft_putchar(c);
	free_container(container);
	return (0);
}

int			process_percent(t_info *info)
{
	char	c;

	c = '%';
	return (print_percent(info, c));
}
