/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:21:48 by wopark            #+#    #+#             */
/*   Updated: 2021/04/14 13:57:10 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		error_message(char *s, t_gamedata *d)
{
	printf("%s error!!\n", s);
	free_gamedata(d);
	ft_exit();
	return (0);
}

int		get_col_size(t_list *lst)
{
	int		ret;
	int		size;

	ret = 0;
	while (lst)
	{
		size = ft_strlen(lst->content);
		if (ret < size)
			ret = size;
		lst = lst->next;
	}
	return (ret);
}

char	**lst2arr(t_gamedata *d, t_list *lst)
{
	char	**ret;
	int		i;

	d->scrn.col_size = get_col_size(lst);
	d->scrn.row_size = ft_lstsize(lst);
	ret = (char **)malloc(sizeof(char *) * (d->scrn.row_size + 1));
	if (!ret)
		return (0);
	i = 0;
	while (lst)
	{
		ret[i] = (char *)malloc(sizeof(char) * d->scrn.col_size + 1);
		if (!ret[i])
		{
			free_split(ret);
			return (0);
		}
		ft_strlcpy(ret[i], lst->content, d->scrn.col_size + 1);
		i++;
		lst = lst->next;
	}
	ret[i] = 0;
	return (ret);
}

void	free_split(char **res)
{
	char	**tmp;

	if (!res)
		return ;
	tmp = res;
	while (*tmp)
		free(*tmp++);
	free(res);
}

void	free_gamedata(t_gamedata *d)
{
	if (d->north_img)
		free(d->north_img);
	if (d->south_img)
		free(d->south_img);
	if (d->west_img)
		free(d->west_img);
	if (d->east_img)
		free(d->east_img);
	if (d->sprite_img)
		free(d->sprite_img);
	if (d->scrn.sprite)
		free(d->scrn.sprite);
	if (d->scrn.buffer)
		free(d->scrn.buffer);
	if (d->scrn.map_arr)
		free_split(d->scrn.map_arr);
}
