#include "../../includes/cub3d.h"

void	init_keys(t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->q = 0;
	key->e = 0;
}

void	init_screen(t_screen *s)
{
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

int		key_pressed(int key, t_key *key_info)
{
	if (key == KEY_W)
		key_info->w = 1;
	else if (key == KEY_S)
		key_info->s = 1;
	else if (key == KEY_A)
		key_info->a = 1;
	else if (key == KEY_D)
		key_info->d = 1;
	else if (key == KEY_Q)
		key_info->q = 1;
	else if (key == KEY_E)
		key_info->e = 1;
	else if (key == KEY_Z){
		if (key_info->z == 1)
			key_info->z = 0;
		else
			key_info->z = 1;
	}
	else if (key == KEY_SHIFT)
		key_info->sft = 1;
	else if (key == KEY_ESC)
		exit(0);
	return (0);
}

int		key_released(int key, t_key *key_info)
{
	if (key == KEY_W)
		key_info->w = 0;
	else if (key == KEY_S)
		key_info->s = 0;
	else if (key == KEY_A)
		key_info->a = 0;
	else if (key == KEY_D)
		key_info->d = 0;
	else if (key == KEY_Q)
		key_info->q = 0;
	else if (key == KEY_E)
		key_info->e = 0;
	else if (key == KEY_SHIFT)
		key_info->sft = 0;
	return (0);
}

void	move_player(t_gamedata *d)
{
	t_vec	np;

	if (d->key.w)
	{
		np = add_vector(d->scrn.p.pos, mul_vector(d->scrn.p.dir, d->scrn.p.move_speed));
		if (d->scrn.map_arr[(int)(d->scrn.p.pos.y)][(int)(np.x)] != '1')
			d->scrn.p.pos.x = np.x;
		if (d->scrn.map_arr[(int)(np.y)][(int)(d->scrn.p.pos.x)] != '1')
			d->scrn.p.pos.y = np.y;
	}
	else if (d->key.s)
	{
		np = add_vector(d->scrn.p.pos, mul_vector(d->scrn.p.dir, -1 * d->scrn.p.move_speed));
		if (d->scrn.map_arr[(int)(d->scrn.p.pos.y)][(int)(np.x)] != '1')
			d->scrn.p.pos.x = np.x;
		if (d->scrn.map_arr[(int)(np.y)][(int)(d->scrn.p.pos.x)] != '1')
			d->scrn.p.pos.y = np.y;
	}
	else if (d->key.a)
	{
		d->scrn.p.dir = rot_vector(d->scrn.p.dir, -1.0f * d->scrn.p.rot_speed);
		d->scrn.plane = rot_vector(d->scrn.plane, -1.0f * d->scrn.p.rot_speed);
	}
	else if (d->key.d)
	{
		d->scrn.p.dir = rot_vector(d->scrn.p.dir, d->scrn.p.rot_speed);
		d->scrn.plane = rot_vector(d->scrn.plane, d->scrn.p.rot_speed);
	}
}

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
void	loop_to_wall(t_screen *s)
{
	while (!s->isHitWall)
	{
		if (s->side.x < s->side.y)
		{
			s->side.x += s->delta.x;
			s->gridX += s->cellX;
			s->isHitSide = 0;
		}
		else
		{
			s->side.y += s->delta.y;
			s->gridY += s->cellY;
			s->isHitSide = 1;
		}
		if (s->map_arr[s->gridY][s->gridX]=='1')
			s->isHitWall = 1;
	}
}
void	draw_texture(t_screen *s, int *img, int x)
{
	double	wall;
	int 	texX;
	int		texY;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;

	lineHeight = (int)(s->height / s->distWall);
	drawStart = -lineHeight / 2 + s->height / 2;
	drawEnd = lineHeight / 2 + s->height / 2;

	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= s->height)
		drawEnd = s->height - 1;
	if (s->isHitSide == 1)
		wall = s->p.pos.x + s->distWall * s->ray.x;
	else
		wall = s->p.pos.y + s->distWall * s->ray.y;
	wall -= floor(wall);

	texX = (int)(wall * (double)64);
	if (s->isHitSide == 0 && s->ray.x < 0)
		texX = 64 - texX - 1;
	if (s->isHitSide == 1 && s->ray.y > 0)
		texX = 64 - texX - 1;

	double		step = 1.0 * 64 / lineHeight;
	double		texPos = (drawStart - s->height / 2 + lineHeight / 2) * step;
	while (drawStart < drawEnd)
	{
		texY = (int)texPos & (64 - 1);
		texPos += step;
		int color = img[64 * texY + texX];
		s->view.addr[s->width * drawStart + x] = color;
		drawStart++;
	}
}
void	check_hit(t_gamedata *d, int x)
{
	t_screen	*s;

	s = &d->scrn;
	s->delta.x = fabs(1 / s->ray.x);
	s->delta.y = fabs(1 / s->ray.y);
	s->isHitWall = 0;
	loop_to_wall(s);
	if (!s->isHitSide)
	{
		if (s->ray.x > 0){
			draw_texture(s, d->east_img, x);
		}
		else
			draw_texture(s, d->west_img, x);
		s->distWall = (s->gridX - s->p.pos.x + (1 - s->cellX) / 2 ) / s->ray.x;
	}
	else
	{
		if (s->ray.y > 0)
			draw_texture(s, d->south_img,x);
		else
			draw_texture(s, d->north_img, x);
		s->distWall = (s->gridY - s->p.pos.y + (1 - s->cellY) / 2 ) / s->ray.y;
	}
}
void	proc_dda(t_screen *s, int x)
{
	s->screenX = 2 * x / (double)s->width - 1;
	s->ray = add_vector(s->p.dir, mul_vector(s->plane, s->screenX));
	s->gridX = (int)(s->p.pos.x);
	s->gridY = (int)(s->p.pos.y);
	if (s->ray.x < 0)
	{
		s->cellX = -1;
		s->side.x = (s->p.pos.x - s->gridX) * s->delta.x;
	}
	else
	{
		s->cellX = 1;
		s->side.x = (s->gridX + 1.0f - s->p.pos.x) * s->delta.x;
	}

	if (s->ray.y < 0)
	{
		s->cellY = -1;
		s->side.y = (s->p.pos.y - s->gridY) * s->delta.y;
	}
	else
	{
		s->cellY = 1;
		s->side.y = (s->gridY + 1.0f - s->p.pos.y) * s->delta.y;
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
		check_hit(d, x);
		x++;
	}
}

int		main_loop(t_gamedata *d)
{
	mlx_clear_window(d->scrn.mlx, d->scrn.win);
	d->scrn.view.ptr = mlx_new_image(d->scrn.mlx, d->scrn.width, d->scrn.height);
	d->scrn.view.addr = (unsigned int *)mlx_get_data_addr(d->scrn.view.ptr, &(d->scrn.view.bpp), &(d->scrn.view.size_line), &(d->scrn.view.endian));
	set_floor_ceil(d);
	ray_cast(d);
	move_player(d);
	mlx_put_image_to_window(d->scrn.mlx, d->scrn.win, d->scrn.view.ptr, 0, 0);
	return (0);
}

int	 cub3d(t_gamedata *d)
{
	t_screen	*s;

	s = &d->scrn;
	init_screen(s);
	init_keys(&d->key);
	mlx_hook(d->scrn.win, 2, 1, key_pressed, &(d->key));
	mlx_hook(d->scrn.win, 3, 2, key_released, &(d->key));
	mlx_loop_hook(d->scrn.mlx, main_loop, d);
	mlx_loop(d->scrn.mlx);
	return (0);
}
