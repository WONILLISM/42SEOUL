/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:44:54 by wopark            #+#    #+#             */
/*   Updated: 2021/04/13 16:46:27 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cal_sprite(t_screen *s, t_sprites *sp, int i)
{
	sp->sprt_pos.x = s->sprite[i].x - s->p.pos.x;
	sp->sprt_pos.y = s->sprite[i].y - s->p.pos.y;
	sp->inv_det = 1.0 / (s->plane.x * s->p.dir.y - s->p.dir.x * s->plane.y);
	sp->transform.x = sp->inv_det * (s->p.dir.y * sp->sprt_pos.x
	- s->p.dir.x * sp->sprt_pos.y);
	sp->transform.y = sp->inv_det * (-s->plane.y * sp->sprt_pos.x
	+ s->plane.x * sp->sprt_pos.y);
	sp->scrnX = (int)((s->width / 2) * (1 + sp->transform.x / sp->transform.y));
	sp->sprt_h = abs((int)(s->height / (sp->transform.y)));
	sp->drawStartY = -sp->sprt_h / 2 + s->height / 2;
	if (sp->drawStartY < 0)
		sp->drawStartY = 0;
	sp->drawEndY = sp->sprt_h / 2 + s->height / 2;
	if (sp->drawEndY >= s->height)
		sp->drawEndY = s->height - 1;
	sp->sprt_w = abs((int)(s->height / (sp->transform.y)));
	sp->drawStartX = -sp->sprt_w / 2 + sp->scrnX;
	if (sp->drawStartX < 0)
		sp->drawStartX = 0;
	sp->drawEndX = sp->sprt_w / 2 + sp->scrnX;
	if (sp->drawEndX >= s->width)
		sp->drawEndX = s->width - 1;
}

void	put_sprites(t_screen *s, t_sprites *sp, int *img)
{
	int		j;
	int		k;

	j = sp->drawStartX;
	while (j < sp->drawEndX)
	{
		sp->texX = (int)(256 * (j - (-sp->sprt_w / 2 + sp->scrnX))
		* 64 / sp->sprt_w) / 256;
		if (sp->transform.y > 0 && j > 0 && j < s->width
		&& sp->transform.y < s->ZBuffer[j])
		{
			k = sp->drawStartY;
			while (k < sp->drawEndY)
			{
				sp->dist = k * 256 - s->height * 128 + sp->sprt_h * 128;
				sp->texY = ((sp->dist * 64) / sp->sprt_h) / 256;
				sp->color = img[64 * sp->texY + sp->texX];
				if ((sp->color & 0x00FFFFFF) != 0)
					s->view.addr[k * s->width + j] = sp->color;
				k++;
			}
		}
		j++;
	}
}

void	draw_sprites(t_screen *s, int *img)
{
	t_sprites	sp;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < s->numofsprt)
	{
		cal_sprite(s, &sp, i);
		put_sprites(s, &sp, img);
		i++;
	}
}

void	proc_sprite(t_screen *s, int *img)
{
	int		i;

	i = 0;
	while (i < s->numofsprt)
	{
		s->sprite[i].dist = ((s->p.pos.x - s->sprite[i].x)
		* (s->p.pos.x - s->sprite[i].x)
		+ (s->p.pos.y - s->sprite[i].y)
		* (s->p.pos.y - s->sprite[i].y));
		i++;
	}
	sort_sprite(s);
	draw_sprites(s, img);
}
