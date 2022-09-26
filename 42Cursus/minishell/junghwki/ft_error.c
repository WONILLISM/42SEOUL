/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:24:31 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/02 20:08:13 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void		err_msg_print(char *str, int exit_stat)
{
	g_archive.exit_stat = exit_stat;
	write(2, str, ft_strlen(str));
}
