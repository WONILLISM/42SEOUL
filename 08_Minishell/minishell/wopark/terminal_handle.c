/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:21:02 by wopark            #+#    #+#             */
/*   Updated: 2021/07/02 16:30:07 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void	set_backspace_key(t_cursor *cursor)
{
	char	*tmp;

	tputs(tgetstr("le", NULL), 1, ft_putchar);
	tputs(tgetstr("dm", NULL), 1, ft_putchar);
	tputs(tgetstr("dc", NULL), 1, ft_putchar);
	tputs(tgetstr("ed", NULL), 1, ft_putchar);
	tmp = cursor->cur->pending;
	if (*tmp)
	{
		(cursor->key_pos)--;
		(cursor->len)--;
		tmp[cursor->key_pos] = 0;
	}
}

void	check_before_history_addback1(
	t_dllist *h_list, t_cursor *cursor, char **input, t_hisnode *last)
{
	cursor->pending = last->pending;
	if (*cursor->pending == 0)
	{
		*input = NULL;
		ft_dll_delhisnode(h_list, last, ft_freehistory);
	}
	cursor->pending = cursor->cur->pending;
	if (*cursor->pending != 0 && cursor->pending && cursor->finished)
	{
		cursor->pending[cursor->key_pos] = 0;
		ft_dll_addhisnode(h_list, NULL, cursor->cur->pending);
		free(cursor->cur->pending);
		cursor->cur->pending = 0;
		*input = h_list->tail->prev->finished;
	}
}

void	check_before_history_addback2(
	t_dllist *h_list, t_cursor *cursor, char **input, t_hisnode *last)
{
	if (*cursor->pending == 0)
	{
		*input = NULL;
		ft_dll_delhisnode(h_list, last, ft_freehistory);
	}
	else if (cursor->pending && cursor->finished == NULL)
	{
		cursor->pending[cursor->key_pos] = 0;
		cursor->cur->finished = ft_strdup(cursor->cur->pending);
		free(cursor->cur->pending);
		cursor->cur->pending = NULL;
		*input = h_list->tail->prev->finished;
	}
}

int		set_printable_key(t_dllist *h_list, t_cursor *cursor, char **input)
{
	t_hisnode	*last;

	input_term(cursor->buf);
	cursor->pending = cursor->cur->pending;
	cursor->finished = cursor->cur->finished;
	if (cursor->buf == '\n')
	{
		last = h_list->tail->prev;
		if (last != cursor->cur)
			check_before_history_addback1(h_list, cursor, input, last);
		else
			check_before_history_addback2(h_list, cursor, input, last);
		cursor->cur = h_list->tail;
		return (0);
	}
	cursor->pending[cursor->key_pos] = cursor->buf;
	cursor->key_pos++;
	cursor->len++;
	cursor->cur->pending = realloc_input(cursor->cur->pending, cursor->len + 1);
	return (1);
}

int		term_key_handler(t_cursor *cursor, t_dllist *h_list, char **input)
{
	char	*pending;

	if (cursor->buf == KEY_BACKSPACE && (cursor->key_pos) > 0)
		set_backspace_key(cursor);
	else if (cursor->buf == KEY_UP)
		return (find_prev_history(h_list, cursor));
	else if (cursor->buf == KEY_DOWN)
		return (find_next_history(h_list, cursor));
	else if (ft_isprint(cursor->buf) || cursor->buf == '\n')
		return (set_printable_key(h_list, cursor, input));
	else if (cursor->buf == CTRL_D)
	{
		pending = cursor->cur->pending;
		if (pending && *pending != 0)
			return (1);
		else
		{
			write(1, "exit\n", 5);
			exit(0);
		}
	}
	return (1);
}
