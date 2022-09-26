/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:23:05 by wopark            #+#    #+#             */
/*   Updated: 2021/06/30 14:25:00 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_hisnode	*ft_dll_newhisnode(void *pending, void *finished)
{
	t_hisnode	*node;

	node = (t_hisnode *)malloc(sizeof(t_hisnode));
	node->pending = ft_strdup(pending);
	node->finished = ft_strdup(finished);
	node->idx = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void		ft_dll_init(t_dllist *list)
{
	list->head = ft_dll_newhisnode(NULL, NULL);
	list->tail = ft_dll_newhisnode(NULL, NULL);
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->length = 0;
}

void		ft_dll_addhisnode(t_dllist *list, void *pending, void *finished)
{
	t_hisnode	*node;

	node = ft_dll_newhisnode(pending, finished);
	node->prev = list->tail->prev;
	node->next = list->tail;
	list->tail->prev->next = node;
	list->tail->prev = node;
	list->length++;
	node->idx = node->prev->idx + 1;
}

void		ft_dll_delhisnode(
	t_dllist *list, t_hisnode *node, void (*del)(void *, void *))
{
	del(node->pending, node->finished);
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	list->length--;
}
