/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:24 by wopark            #+#    #+#             */
/*   Updated: 2020/10/23 15:28:06 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef	struct	s_info
{
	int		n;
	int		minus;
	int		width;
	int		precision;
	int		zero;
	int		plus;
	int		space;
	int		hex;
	int		len;
}				t_info;

int	ft_printf(const char *, ...);

#endif
