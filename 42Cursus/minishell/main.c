/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:07:54 by wopark            #+#    #+#             */
/*   Updated: 2021/07/02 18:13:28 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minish.h"

char				*realloc_input(char *ptr, size_t size)
{
	char			*ret;

	ret = (char *)malloc(size);
	if (!ret)
		return (0);
	ft_memmove(ret, ptr, size);
	free(ptr);
	return (ret);
}

void				init_input(t_dllist *h_list)
{
	char			*pending;
	char			*finished;

	pending = (char *)malloc(sizeof(char));
	*pending = 0;
	finished = NULL;
	ft_dll_addhisnode(h_list, pending, finished);
	free(pending);
}

int					get_input(char **input, t_dllist *h_list)
{
	struct termios	term;
	struct termios	term_backup;
	t_cursor		*cursor;

	cursor = get_cursor();
	term_init(&term, &term_backup);
	cursor_init(cursor, h_list);
	init_input(h_list);
	cursor->cur = h_list->tail->prev;
	while (1)
	{
		cursor->buf = 0;
		cursor->r_nbr = read(STDIN_FILENO, &cursor->buf, sizeof(cursor->buf));
		if (!term_key_handler(cursor, h_list, input))
		{
			tcsetattr(STDIN_FILENO, TCSANOW, &term_backup);
			return (READ_SUC);
		}
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term_backup);
	return (READ_ERR);
}

int					main(int argc, char **argv, char **envv)
{
	t_dllist		history_lst;
	char			*input;

	ft_dll_init(&history_lst);
	signal_init(argc, argv);
	envv_lst_make(envv);
	while (1)
	{
		write(1, "minish $> ", 10);
		if (get_input(&input, &history_lst) == READ_ERR)
			printf("Error");
		if (parse_input(input) == ERROR)
			parse_error_msg(SYNTAX_ERROR_MSG);
	}
	return (0);
}
