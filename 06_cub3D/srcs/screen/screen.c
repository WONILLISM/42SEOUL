#include "../../includes/cub3d.h"

// void	draw_map(t_archive *a)
// {
// 	int		i;
// 	int		j;
// 	double		mapSizeX;
// 	double		mapSizeY;

// 	mapSizeX = a->width/4;
// 	mapSizeY = a->height/4;
// 	// i = 0;
// 	// while (i <= mapSizeY){
// 	// 	j = 0;
// 	// 	while (j <= mapSizeX){
// 	// 		if (i % (int)(mapSizeY/a->row_size) != 0 && j % (int)(mapSizeY/a->row_size) != 0){
// 	// 			if (a->map_arr[(int)(i/(mapSizeY/a->row_size))][(int)(j/(mapSizeX/a->col_size))] == '1'){
// 	// 				if (!a->s.view.addr[(a->width) * i + j])
// 	// 					a->s.view.addr[(a->width) * i + j] = 0x2e3258;
// 	// 				else
// 	// 					a->s.view.addr[(a->width) * i + j] += 0x44000000;
// 	// 			}
// 	// 			else if (a->map_arr[(int)(i/(mapSizeY/10))][(int)(j/(mapSizeX/10))] == '2'){
// 	// 				if (!a->s.view.addr[(a->width) * i + j])
// 	// 					a->s.view.addr[(a->width) * i + j] = 0x653865;
// 	// 				else
// 	// 					a->s.view.addr[(a->width) * i + j] += 0x44000000;
// 	// 			}
// 	// 			else
// 	// 				a->s.view.addr[(a->width) * i + j] = 0x222222;
// 	// 		}
// 	// 		else{
// 	// 			if (!a->s.view.addr[(a->width) * i + j])
// 	// 				a->s.view.addr[(a->width) * i + j] = 0x000000;
// 	// 			// else
// 	// 				// a->s.view.addr[(a->width) * i + j] = 0xffffff;
// 	// 		}
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// }
// 	// i = -1;
// 	// while (i < 2){
// 	// 	j = -1;
// 	// 	while (j < 2){
// 	// 		a->s.view.addr[(a->width) * (int)(a->p.pos.y/(a->row_size) * mapSizeY + i) + (int)(a->p.pos.x/(a->col_size) * mapSizeX + j)] = 0xffff00;
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// }
// }
void	set_floor_ceil(t_gamedata *d)
{
	t_screen *s;
	int		i;
	int		j;

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
	d->scrn.view.ptr = mlx_new_image(d->scrn.mlx, d->scrn.width, d->scrn.height);
	d->scrn.view.addr = (unsigned int *)mlx_get_data_addr(d->scrn.view.ptr, &(d->scrn.view.bpp), &(d->scrn.view.size_line), &(d->scrn.view.endian));
	set_floor_ceil(d);
	ray_cast(d);
	manage_player(d);
	if (d->argc == 3)
		save_bitmap(d);
	mlx_put_image_to_window(d->scrn.mlx, d->scrn.win, d->scrn.view.ptr, 0, 0);
	return (0);
}
//map error
int		 cub3d(t_gamedata *d)
{
	t_screen	*s;

	s = &d->scrn;
	init_screen(s);
	init_sprite(s);
	init_keys(&d->key);
	mlx_hook(d->scrn.win, 2, 1, key_pressed, &(d->key));
	mlx_hook(d->scrn.win, 3, 2, key_released, &(d->key));
	mlx_loop_hook(d->scrn.mlx, main_loop, d);
	mlx_loop(d->scrn.mlx);
	return (0);
}
