/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:58:08 by wopark            #+#    #+#             */
/*   Updated: 2020/10/31 20:37:20 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_int(t_info *info, char *res)
{
	int	ret;

	info->hex = 0;
	ret = ft_strlen(res);
	ft_putstr_fd(res, 1);
	return (ret);
}

static char	*process_width(t_info *info, char *res)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(res);
	if (info->width <= len)
		return (res);
	if (!(ret = (char *)malloc(sizeof(char) * (info->width + 1))))
		return (NULL);
	if (info->left)
	{
		ft_strlcpy(ret, res, len);
		i = len;
		while (ret[i])
			ret[i++] = ' ';
	}
	else
	{
		i = 0;
		if (res[0] == '-')
		{
			ret[i++] = '-';
			res++;
			len--;
		}
		if ()
		while (i < info->width + 1 - len)
			ret[i++] = '0'

	}
	return (0);
}

static char	*process_precision(t_info *info, char *res)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(res);
	if (res[0] == '0' && info->precision == 0)
		res = "";
	if (info->precision <= len)
		return (res);
	if (!(ret = (char *)malloc(sizeof(char) * (info->precision + 1))))
		return (NULL);
	i = 0;
	if (res[0] == '-')
	{
		ret[i++] = '-';
		res++;
		len--;
		info->precision++;
	}
	while (i < info->precision - len)
		ret[i++] = '0';
	while (*res)
		ret[i++] = *res++;
	ret[i] = 0;
	return (ret);
}

int			process_int(va_list ap, t_info *info)
{
	char	*res;
	int		len;

	len = 0;
	res = ft_itoa(((int)va_arg(ap, int)));
	if (!(res = process_precision(info, res)))
		return _ERROR;

	return (print_int(info, res));
}

/*
** %d, %i
** precision
** 1. precision > 들어온 정수값 길이(len) : precision - len 만큼 앞에 0을 채움
** 2.
*/
