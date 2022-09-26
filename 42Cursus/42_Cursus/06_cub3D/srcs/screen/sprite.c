/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:44:54 by wopark            #+#    #+#             */
/*   Updated: 2021/04/14 13:54:14 by wopark           ###   ########.fr       */
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
	sp->scrn_x =
	(int)((s->width / 2) * (1 + sp->transform.x / sp->transform.y));
	sp->sprt_h = abs((int)(s->height / (sp->transform.y)));
	sp->draw_start_y = -sp->sprt_h / 2 + s->height / 2;
	if (sp->draw_start_y < 0)
		sp->draw_start_y = 0;
	sp->draw_end_y = sp->sprt_h / 2 + s->height / 2;
	if (sp->draw_end_y >= s->height)
		sp->draw_end_y = s->height - 1;
	sp->sprt_w = abs((int)(s->height / (sp->transform.y)));
	sp->draw_start_x = -sp->sprt_w / 2 + sp->scrn_x;
	if (sp->draw_start_x < 0)
		sp->draw_start_x = 0;
	sp->draw_end_x = sp->sprt_w / 2 + sp->scrn_x;
	if (sp->draw_end_x >= s->width)
		sp->draw_end_x = s->width - 1;
}

void	put_sprites(t_screen *s, t_sprites *sp, int *img)
{
	int		j;
	int		k;

	j = sp->draw_start_x;
	while (j < sp->draw_end_x)
	{
		sp->tex_x = (int)(256 * (j - (-sp->sprt_w / 2 + sp->scrn_x))
		* 64 / sp->sprt_w) / 256;
		if (sp->transform.y > 0 && j > 0 && j < s->width
		&& sp->transform.y < s->buffer[j])
		{
			k = sp->draw_start_y;
			while (k < sp->draw_end_y)
			{
				sp->dist = k * 256 - s->height * 128 + sp->sprt_h * 128;
				sp->tex_y = ((sp->dist * 64) / sp->sprt_h) / 256;
				sp->color = img[64 * sp->tex_y + sp->tex_x];
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
