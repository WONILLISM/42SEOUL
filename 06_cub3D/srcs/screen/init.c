/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:33:09 by wopark            #+#    #+#             */
/*   Updated: 2021/04/14 12:44:03 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_keys(t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->up = 0;
	key->down = 0;
	key->left = 0;
	key->right = 0;
}

void	init_screen(t_screen *s)
{
	s->ZBuffer = (double *)malloc(sizeof(double) * s->width);
	s->screenX = 0;
	s->distWall = 0;
	s->ray.x = 0.0f;
	s->ray.y = 0.0f;
	s->side.x = 0.0f;
	s->side.y = 0.0f;
	s->delta.x = 0.0f;
	s->delta.y = 0.0f;
	s->gridX = 0;
	s->gridY = 0;
	s->cellX = 0;
	s->cellY = 0;
	s->isHitSide = 0;
	s->isHitWall = 0;
}

void	chk_cubfile(t_gamedata *d, char *s)
{
	int		len;
	int		i;
	char	*cub;

	i = 4;
	len = ft_strlen(s);
	cub = ".cub";
	if (len <= ft_strlen(cub))
		error_message("cub file", d);
	while (--i >= 0)
	{
		if (s[len - 1] != cub[i])
			error_message("cub file", d);
		len--;
	}
}
