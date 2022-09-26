/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:19:21 by wopark            #+#    #+#             */
/*   Updated: 2021/06/30 14:19:33 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_cursor	*get_cursor(void)
{
	static t_cursor	cursor;

	return (&cursor);
}

void		cursor_init(t_cursor *cursor, t_dllist *h_list)
{
	cursor->buf = 0;
	cursor->idx = 0;
	cursor->len = 0;
	cursor->key_pos = 0;
	cursor->cur = h_list->tail;
	(void)h_list;
}
