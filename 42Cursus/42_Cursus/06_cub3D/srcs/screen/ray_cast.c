/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:34:59 by wopark            #+#    #+#             */
/*   Updated: 2021/04/14 13:53:29 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	loop_to_wall(t_screen *s)
{
	while (!s->is_hit_wall)
	{
		if (s->side.x < s->side.y)
		{
			s->side.x += s->delta.x;
			s->grid_x += s->cell_x;
			s->is_hit_side = 0;
		}
		else
		{
			s->side.y += s->delta.y;
			s->grid_y += s->cell_y;
			s->is_hit_side = 1;
		}
		if (s->map_arr[s->grid_y][s->grid_x] == '1')
			s->is_hit_wall = 1;
	}
	s->tex.line_height = (int)(s->height / s->dist_wall);
	s->tex.draw_start = -s->tex.line_height / 2 + s->height / 2;
	s->tex.draw_end = s->tex.line_height / 2 + s->height / 2;
}

void	draw_texture(t_screen *s, int *img, int x)
{
	if (s->tex.draw_start < 0)
		s->tex.draw_start = 0;
	if (s->tex.draw_end >= s->height)
		s->tex.draw_end = s->height - 1;
	if (s->is_hit_side == 1)
		s->tex.wall = s->p.pos.x + s->dist_wall * s->ray.x;
	else
		s->tex.wall = s->p.pos.y + s->dist_wall * s->ray.y;
	s->tex.wall -= floor(s->tex.wall);
	s->tex.tex_x = (int)(s->tex.wall * (double)64);
	if (s->is_hit_side == 0 && s->ray.x < 0)
		s->tex.tex_x = 64 - s->tex.tex_x - 1;
	if (s->is_hit_side == 1 && s->ray.y > 0)
		s->tex.tex_x = 64 - s->tex.tex_x - 1;
	s->tex.step = 1.0 * 64 / s->tex.line_height;
	s->tex.tex_pos = (s->tex.draw_start - s->height
	/ 2 + s->tex.line_height / 2) * s->tex.step;
	while (s->tex.draw_start < s->tex.draw_end)
	{
		s->tex.tex_y = (int)s->tex.tex_pos & (64 - 1);
		s->tex.tex_pos += s->tex.step;
		s->view.addr[s->width * s->tex.draw_start + x] =
		img[64 * s->tex.tex_y + s->tex.tex_x];
		s->tex.draw_start++;
	}
}

void	check_hit(t_gamedata *d, t_screen *s, int x)
{
	s->delta.x = fabs(1 / s->ray.x);
	s->delta.y = fabs(1 / s->ray.y);
	s->is_hit_wall = 0;
	loop_to_wall(s);
	if (!s->is_hit_side)
	{
		if (s->ray.x > 0)
			draw_texture(s, d->east_img, x);
		else
			draw_texture(s, d->west_img, x);
		s->dist_wall =
		(s->grid_x - s->p.pos.x + (1 - s->cell_x) / 2) / s->ray.x;
	}
	else
	{
		if (s->ray.y > 0)
			draw_texture(s, d->south_img, x);
		else
			draw_texture(s, d->north_img, x);
		s->dist_wall =
		(s->grid_y - s->p.pos.y + (1 - s->cell_y) / 2) / s->ray.y;
	}
	s->buffer[x] = s->dist_wall;
}

void	proc_dda(t_screen *s, int x)
{
	s->scrn_x = 2 * x / (double)s->width - 1;
	s->ray = add_vector(s->p.dir, mul_vector(s->plane, s->scrn_x));
	s->grid_x = (int)(s->p.pos.x);
	s->grid_y = (int)(s->p.pos.y);
	if (s->ray.x < 0)
	{
		s->cell_x = -1;
		s->side.x = (s->p.pos.x - s->grid_x) * s->delta.x;
	}
	else
	{
		s->cell_x = 1;
		s->side.x = (s->grid_x + 1.0f - s->p.pos.x) * s->delta.x;
	}
	if (s->ray.y < 0)
	{
		s->cell_y = -1;
		s->side.y = (s->p.pos.y - s->grid_y) * s->delta.y;
	}
	else
	{
		s->cell_y = 1;
		s->side.y = (s->grid_y + 1.0f - s->p.pos.y) * s->delta.y;
	}
}

void	ray_cast(t_gamedata *d)
{
	t_screen	*s;
	int			x;

	s = &d->scrn;
	x = 0;
	while (x < s->width)
	{
		proc_dda(s, x);
		check_hit(d, s, x);
		x++;
	}
	proc_sprite(s, d->sprite_img);
}
