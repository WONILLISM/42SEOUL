/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:15:09 by wopark            #+#    #+#             */
/*   Updated: 2021/07/02 18:34:57 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			new_line(void)
{
	t_cursor	*cursor;

	tputs(tgetstr("do", NULL), 1, ft_putchar);
	tputs(tgetstr("ll", NULL), 1, ft_putchar);
	cursor = get_cursor();
	cursor->key_pos = 0;
	cursor->len = cursor->key_pos;
	ft_putstr_fd("minish $> ", STDOUT);
	return (SUCCESS);
}

void		signal_multi_process(int signo, int status)
{
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT);
		if ((status & 0xff) == 0)
			g_archive.exit_stat = ((status >> 8) & 0xff);
		else
			g_archive.exit_stat = (status & 0xff) + 128;
	}
	else if (signo == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", STDOUT);
		if ((status & 0xff) == 0)
			g_archive.exit_stat = ((status >> 8) & 0xff);
		else
			g_archive.exit_stat = (status & 0xff) + 128;
	}
}

void		signal_handler(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, 0);
	if (signo == SIGINT)
	{
		if (pid == -1)
		{
			new_line();
			g_archive.exit_stat = 1;
		}
		else
			signal_multi_process(signo, status);
	}
	else if (signo == SIGQUIT && pid != -1)
		signal_multi_process(signo, status);
}

void		signal_init(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}
