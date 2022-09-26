/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:15:27 by wopark            #+#    #+#             */
/*   Updated: 2021/07/02 20:08:12 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void	print_prompt(void)
{
	tputs(tgetstr("im", NULL), 1, ft_putchar);
	tputs(tgetstr("ic", NULL), 1, ft_putchar);
	ft_putstr_fd("minish $> ", 1);
	tputs(tgetstr("ip", NULL), 1, ft_putchar);
	tputs(tgetstr("ei", NULL), 1, ft_putchar);
}

void	term_del_line(t_cursor *cursor, t_dllist *h_list)
{
	int			len;
	int			row;

	len = tgetnum("co");
	row = (cursor->len + 10) / len + 1;
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	tputs(tgetstr("dm", NULL), 1, ft_putchar);
	while (row--)
	{
		tputs(tgetstr("dl", NULL), 1, ft_putchar);
		if (row)
			tputs(tgetstr("up", NULL), 1, ft_putchar);
	}
	tputs(tgetstr("ed", NULL), 1, ft_putchar);
	while (len--)
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	cursor_init(cursor, h_list);
}

int		find_prev_history(t_dllist *h_list, t_cursor *cursor)
{
	t_hisnode	*node;
	char		*tmp;

	node = cursor->cur;
	if (node->prev)
	{
		if (node->prev->finished)
		{
			tmp = node->prev->pending;
			if (node->prev->pending == NULL)
				node->prev->pending = ft_strdup(node->prev->finished);
			term_del_line(cursor, h_list);
			cursor->cur = node->prev;
			print_prompt();
			cursor->key_pos = ft_strlen(cursor->cur->pending);
			cursor->len = cursor->key_pos;
			write(1, cursor->cur->pending, cursor->len);
		}
	}
	return (1);
}

int		find_next_history(t_dllist *h_list, t_cursor *cursor)
{
	t_hisnode	*node;

	node = cursor->cur;
	if (node->next && (node->next->finished || node->next->pending))
	{
		term_del_line(cursor, h_list);
		cursor->cur = node->next;
		print_prompt();
		if (!node->next->finished)
		{
			if (node->next->pending)
				write(1, cursor->cur->pending, ft_strlen(cursor->cur->pending));
			else
			{
				cursor->key_pos = 0;
				cursor->len = 0;
			}
			return (1);
		}
		cursor->key_pos = ft_strlen(cursor->cur->pending);
		cursor->len = cursor->key_pos;
		write(1, cursor->cur->pending, cursor->len);
	}
	return (1);
}
