/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:24 by wopark            #+#    #+#             */
/*   Updated: 2020/11/08 15:39:06 by wopark           ###   ########.fr       */
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

void		print_info(t_info *info);

/*
** ft printf
*/
int		ft_printf(const char *, ...);
char	*proc_flag(t_info *info, char *res);

/*
** proc container
*/
t_container	*init_container(void);
char		*set_container(int size, char padding_info);
void		free_container(t_container *c);

/*
** proc_sign
*/
char	*set_sign(t_info *info, char *res);
char	*proc_sign(t_info *info, char *container, int len);

/*
** printf Parser
*/
void		flags_parser(const char **format, t_info *info);
void		precision_parser(const char **format, va_list ap, t_info *info);
void		width_parser(const char **format, va_list ap, t_info *info);

/*
** process int
*/
int			process_int(va_list ap, t_info *info);

/*
** process char
*/
int			process_char(va_list ap, t_info *info);

/*
** process string
*/
int			process_string(va_list ap, t_info *info);

/*
** process unsigned int
*/
int			process_unsigned_int(va_list ap, t_info *info);

/*
** process hex
*/
int			process_hex(va_list ap, t_info *info, char c);

/*
** process pointer
*/
int			process_pointer(va_list ap, t_info *info);

/*
** process per
*/
int			process_percent(t_info *info);

/*
** process n
*/
int			process_n(va_list ap, t_info *info);
#endif
