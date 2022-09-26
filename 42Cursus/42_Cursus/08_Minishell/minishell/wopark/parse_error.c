/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:31:32 by wopark            #+#    #+#             */
/*   Updated: 2021/07/02 19:20:54 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		parse_error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	g_archive.exit_stat = 258;
	return (0);
}
