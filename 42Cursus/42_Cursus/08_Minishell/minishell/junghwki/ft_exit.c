/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:24:17 by junghwki          #+#    #+#             */
/*   Updated: 2021/06/30 14:03:18 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

long long		ft_atoll(const char *str)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + sign * (*str - '0');
		str++;
	}
	return (ret);
}

int				ft_isdigit_str(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		str++;
	}
	return (0);
}

int				arg_check(char *str)
{
	char		*long_long_max;

	long_long_max = "9223372036854775807";
	if (*str == '+' || *str == '-')
		str++;
	if (ft_isdigit_str(str) < 0)
		return (-1);
	if (ft_strlen(str) > 19)
		return (-1);
	else if (ft_strlen(str) == 19)
	{
		while (*str)
		{
			if (*long_long_max == *str)
			{
				long_long_max++;
				str++;
			}
			else if (*long_long_max > *str)
				return (1);
			else if (*long_long_max < *str)
				return (-1);
		}
	}
	return (1);
}

void			numeric_err(char *str)
{
	write(2, "minish: exit: ", 14);
	write(2, str, ft_strlen(str));
	err_msg_print(": numeric argument required\n", 255);
	exit(g_archive.exit_stat);
}

void			ft_exit(t_cmd *cmd, int pipe_flag)
{
	if (!(cmd->argv[1]))
	{
		if (!pipe_flag)
			write(2, "exit\n", 5);
		exit(g_archive.exit_stat);
	}
	if (cmd->argv[2])
	{
		if (ft_isdigit_str(cmd->argv[1]) < 0)
			numeric_err(cmd->argv[1]);
		else
			err_msg_print("minish: exit: too many arguments\n", 1);
	}
	else
	{
		if (arg_check(cmd->argv[1]) < 0)
			numeric_err(cmd->argv[1]);
		g_archive.exit_stat = ft_atoll(cmd->argv[1]);
		if (!pipe_flag)
			write(2, "exit\n", 5);
		exit(g_archive.exit_stat);
	}
}
