/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:24 by wopark            #+#    #+#             */
/*   Updated: 2020/10/31 20:37:19 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define _ERROR -1

# define FLAG "-+ 0#"
# define LEN_MODIFIER "hl"
# define CONVERSION "cspdiuxXn%"
# define DEMICAL "0123456789"
# define UPPER_HEX "0123456789ABCDEF"
# define LOWER_HEX "0123456789abcdef"

typedef	struct	s_info
{
	int		n;

	int		left;
	int		plus;
	int		space;
	int		zero;
	int		hash;

	int		width;
	int		precision;

	int		hex;

	char	sign;
	char	padding;
}				t_info;

typedef struct	s_container
{
	char	*width;
	char	*precision;
}				t_container;


/*
** ft printf
*/
int		ft_printf(const char *, ...);
char	*proc_flag(t_info *info, char *res);

/*
** ft printf Parser
*/
void	flags_parser(const char **format, t_info *info);
void	precision_parser(const char **format, va_list ap, t_info *info);
void	width_parser(const char **format, va_list ap, t_info *info);

/*
** ft process int
*/
int			print_int(t_info *info, char *res);
int			process_int(va_list ap, t_info *info);
#endif
