/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:43:01 by wopark            #+#    #+#             */
/*   Updated: 2021/04/13 16:44:10 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_floor_ceil(t_gamedata *d)
{
	t_screen	*s;
	int			i;
	int			j;

	s = &d->scrn;
	i = 0;
	while (i < s->height)
	{
		j = 0;
		while (j < s->width)
		{
			if (i > s->height / 2)
				s->view.addr[(s->width) * i + j] = d->floor_color;
			else
				s->view.addr[(s->width) * i + j] = d->ceil_color;
			j++;
		}
		i++;
	}
}

int		main_loop(t_gamedata *d)
{
	mlx_clear_window(d->scrn.mlx, d->scrn.win);
	d->scrn.view.ptr = mlx_new_image(
		d->scrn.mlx, d->scrn.width, d->scrn.height);
	d->scrn.view.addr = (unsigned int *)mlx_get_data_addr(
		d->scrn.view.ptr, &(d->scrn.view.bpp), &(d->scrn.view.size_line),
		&(d->scrn.view.endian));
	set_floor_ceil(d);
	ray_cast(d);
	manage_player(d);
	if (d->argc == 3)
		save_bitmap(d);
	mlx_put_image_to_window(d->scrn.mlx, d->scrn.win, d->scrn.view.ptr, 0, 0);
	return (0);
}

int		cub3d(t_gamedata *d)
{
	t_screen	*s;

	s = &d->scrn;
	init_screen(s);
	init_sprite(s);
	init_keys(&d->key);
	mlx_hook(d->scrn.win, 2, 1, key_pressed, &(d->key));
	mlx_hook(d->scrn.win, 3, 2, key_released, &(d->key));
	mlx_hook(d->scrn.win, 17, 0, ft_exit, 0);
	mlx_loop_hook(d->scrn.mlx, main_loop, d);
	mlx_loop(d->scrn.mlx);
	return (0);
}
