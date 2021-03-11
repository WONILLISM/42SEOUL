#include "../includes/cub3d.h"

void	init_window(t_archive *a)
{
	a->m.mlx = mlx_init();
	a->m.win = mlx_new_window(a->m.mlx, a->width, a->height, "cub3d");
}

void	init_keys(t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->q = 0;
	key->e = 0;
}
// void	init_player(t_player *p)
// {
// 	p->pos.x = 8.5f;
// 	p->pos.y = 8.5f;
// 	p->move_speed = 0.05f;
// 	p->rot_speed = 0.02f;
// 	p->dir.x = 0.0f;
// 	p->dir.y = 1.0f;
// }

void	init_screen(t_screen *s)
{
	// s->plane.x = 0.0f;
	// s->plane.y = -0.66f;
	s->delta.x = 0.0f;
	s->delta.y = 0.0f;
	s->ray.x = 0.0f;
	s->ray.y = 0.0f;
	s->side.x = 0.0f;
	s->side.y = 0.0f;
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

void	move_player(t_archive *a)
{
	t_vec	np;
	t_vec	nd;

	if (a->key.w)
	{
		np = add_vector(a->p.pos, mul_vector(a->p.dir, a->p.move_speed));
		if (a->map[(int)(a->p.pos.y)][(int)(np.x)] != '1')
			a->p.pos.x = np.x;
		if (a->map[(int)(np.y)][(int)(a->p.pos.x)] != '1')
			a->p.pos.y = np.y;
	}
	else if (a->key.s)
	{
		np = add_vector(a->p.pos, mul_vector(a->p.dir, -1 * a->p.move_speed));
		if (a->map[(int)(a->p.pos.y)][(int)(np.x)] != '1')
			a->p.pos.x = np.x;
		if (a->map[(int)(np.y)][(int)(a->p.pos.x)] != '1')
			a->p.pos.y = np.y;
	}
	else if (a->key.a)
	{
		a->p.dir = rot_vector(a->p.dir, -1.0f * a->p.rot_speed);
		a->s.plane = rot_vector(a->s.plane, -1.0f * a->p.rot_speed);
	}
	else if (a->key.d)
	{
		a->p.dir = rot_vector(a->p.dir, a->p.rot_speed);
		a->s.plane = rot_vector(a->s.plane, a->p.rot_speed);
	}
}

void	draw_map(t_archive *a)
{
	int		i;
	int		j;
	double		mapSizeX;
	double		mapSizeY;

	mapSizeX = a->width/4;
	mapSizeY = a->height/4;
	printf("%f %f\n", mapSizeX, mapSizeY);
	// i = 0;
	// while (i <= mapSizeY){
	// 	j = 0;
	// 	while (j <= mapSizeX){
	// 		if (i % (int)(mapSizeY/a->row_size) != 0 && j % (int)(mapSizeY/a->row_size) != 0){
	// 			if (a->map[(int)(i/(mapSizeY/a->row_size))][(int)(j/(mapSizeX/a->col_size))] == '1'){
	// 				if (!a->s.view.addr[(a->width) * i + j])
	// 					a->s.view.addr[(a->width) * i + j] = 0x2e3258;
	// 				else
	// 					a->s.view.addr[(a->width) * i + j] += 0x44000000;
	// 			}
	// 			else if (a->map[(int)(i/(mapSizeY/10))][(int)(j/(mapSizeX/10))] == '2'){
	// 				if (!a->s.view.addr[(a->width) * i + j])
	// 					a->s.view.addr[(a->width) * i + j] = 0x653865;
	// 				else
	// 					a->s.view.addr[(a->width) * i + j] += 0x44000000;
	// 			}
	// 			else
	// 				a->s.view.addr[(a->width) * i + j] = 0x222222;
	// 		}
	// 		else{
	// 			if (!a->s.view.addr[(a->width) * i + j])
	// 				a->s.view.addr[(a->width) * i + j] = 0x000000;
	// 			// else
	// 				// a->s.view.addr[(a->width) * i + j] = 0xffffff;
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	// i = -1;
	// while (i < 2){
	// 	j = -1;
	// 	while (j < 2){
	// 		a->s.view.addr[(a->width) * (int)(a->p.pos.y/(a->row_size) * mapSizeY + i) + (int)(a->p.pos.x/(a->col_size) * mapSizeX + j)] = 0xffff00;
	// 		j++;
	// 	}
	// 	i++;
	// }
}
void	set_floor_ceil(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->a.height)
	{
		j = 0;
		while (j < d->a.width)
		{
			if (i > d->a.height / 2)
				d->a.s.view.addr[(d->a.width) * i + j] = d->floor_color;
			else
				d->a.s.view.addr[(d->a.width) * i + j] = d->ceil_color;
			j++;
		}
		i++;
	}
}
void	loop_to_wall(t_archive *a)
{
	while (!a->s.isHitWall)
	{
		if (a->s.side.x < a->s.side.y)
		{
			a->s.side.x += a->s.delta.x;
			a->s.gridX += a->s.cellX;
			a->s.isHitSide = 0;
		}
		else
		{
			a->s.side.y += a->s.delta.y;
			a->s.gridY += a->s.cellY;
			a->s.isHitSide = 1;
		}
		if (a->map[a->s.gridY][a->s.gridX]=='1')
			a->s.isHitWall = 1;
	}
}
void	draw_texture(t_archive *a, int *img, int x)
{
	double	wall;
	int 	texX;
	int		texY;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;

	lineHeight = (int)(a->height / a->s.distWall);
	drawStart = -lineHeight / 2 + a->height / 2;
	drawEnd = lineHeight / 2 + a->height / 2;

	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= a->height)
		drawEnd = a->height - 1;
	if (a->s.isHitSide == 1)
		wall = a->p.pos.x + a->s.distWall * a->s.ray.x;
	else
		wall = a->p.pos.y + a->s.distWall * a->s.ray.y;
	wall -= floor(wall);

	texX = (int)(wall * (double)64);
	if (a->s.isHitSide == 0 && a->s.ray.x < 0)
		texX = 64 - texX - 1;
	if (a->s.isHitSide == 1 && a->s.ray.y > 0)
		texX = 64 - texX - 1;

	double		step = 1.0 * 64 / lineHeight;
	double		texPos = (drawStart - a->height / 2 + lineHeight / 2) * step;
	while (drawStart < drawEnd)
	{
		texY = (int)texPos & (64 - 1);
		texPos += step;
		int color = img[64 * texY + texX];
		a->s.view.addr[a->width * drawStart + x] = color;
		drawStart++;
	}
}
int		check_hit(t_data *d, int x)
{
	t_archive	*a;
	int			color;

	a = &d->a;
	a->s.delta.x = fabs(1 / a->s.ray.x);
	a->s.delta.y = fabs(1 / a->s.ray.y);
	a->s.isHitWall = 0;
	loop_to_wall(a);
	if (!a->s.isHitSide)//좌 우
	{
		if (a->s.ray.x > 0){		//동
			draw_texture(a, d->east, x);
			// color = 0xb35f44;
		}
		else					//서
			draw_texture(a, d->west, x);
			// color = 0xffffff;
		a->s.distWall = (a->s.gridX - a->p.pos.x + (1 - a->s.cellX) / 2 ) / a->s.ray.x;
	}
	else// 위 아래
	{
		if (a->s.ray.y > 0)		//남
			draw_texture(a, d->south,x);
			// color = 0xffffff;
		else					//북
			draw_texture(a, d->north, x);
			// color = 0xffffff;
		a->s.distWall = (a->s.gridY - a->p.pos.y + (1 - a->s.cellY) / 2 ) / a->s.ray.y;
	}
	return (color);
}
void	proc_dda(t_archive *a, int x)
{
	a->s.screenX = 2 * x / (double)a->width - 1;
	a->s.ray = add_vector(a->p.dir, mul_vector(a->s.plane, a->s.screenX));
	a->s.gridX = (int)(a->p.pos.x);
	a->s.gridY = (int)(a->p.pos.y);
	// printf("%f %f\n", a->s.ray.x, a->s.ray.y);
	if (a->s.ray.x < 0)
	{
		a->s.cellX = -1;
		a->s.side.x = (a->p.pos.x - a->s.gridX) * a->s.delta.x;
	}
	else
	{
		a->s.cellX = 1;
		a->s.side.x = (a->s.gridX + 1.0f - a->p.pos.x) * a->s.delta.x;
	}

	if (a->s.ray.y < 0)
	{
		a->s.cellY = -1;
		a->s.side.y = (a->p.pos.y - a->s.gridY) * a->s.delta.y;
	}
	else
	{
		a->s.cellY = 1;
		a->s.side.y = (a->s.gridY + 1.0f - a->p.pos.y) * a->s.delta.y;
	}
}
void	ray_cast(t_data *d)
{
	t_archive	*a;
	int			x;
	// int			lineHeight;
	// int			drawStart;
	// int			drawEnd;
	int			color;

	a = &d->a;
	x = 0;
	while (x < a->width)
	{
		proc_dda(a, x);
		color = check_hit(d, x);
		// lineHeight = (int)(a->height / a->s.distWall);
		// drawStart = -lineHeight / 2 + a->height / 2;
		// drawEnd = lineHeight / 2 + a->height / 2;
		// if (drawStart < 0)
		// 	drawStart = 0;
		// if (drawEnd >= a->height)
		// 	drawEnd = a->height - 1;
		// while (drawStart < drawEnd)
		// {
		// 	a->s.view.addr[a->width * (drawStart++) + x] = color;
		// }
		// x++;
		x++;
	}
}

int		main_loop(t_data *d)
{
	mlx_clear_window(d->a.m.mlx, d->a.m.win);
	d->a.s.view.ptr = mlx_new_image(d->a.m.mlx, d->a.width, d->a.height);
	d->a.s.view.addr = (unsigned int *)mlx_get_data_addr(d->a.s.view.ptr, &(d->a.s.view.bpp), &(d->a.s.view.size_line), &(d->a.s.view.endian));
	set_floor_ceil(d);
	ray_cast(d);
	if (d->a.key.z == 1)
		draw_map(&d->a);
	move_player(&d->a);
	mlx_put_image_to_window(d->a.m.mlx, d->a.m.win, d->a.s.view.ptr, 0, 0);
	return (0);
}

int	 cub3d(t_data *d)
{
	init_window(&d->a);
	// init_player(&d->a.p);
	init_screen(&d->a.s);
	init_keys(&d->a.key);
	// xpm2img(d);
	mlx_hook(d->a.m.win, 2, 1, key_pressed, &(d->a.key));
	mlx_hook(d->a.m.win, 3, 2, key_released, &(d->a.key));
	mlx_loop_hook(d->a.m.mlx, main_loop, &d->a);
	mlx_loop(d->a.m.mlx);
	return (0);
}
// int	 main(void)
// {
// 	t_archive	archive;

// 	init_window(&archive);
// 	init_player(&archive.p);
// 	init_screen(&archive.s);

// 	mlx_hook(archive.m.win, 2, 1, key_pressed, &(archive.key));
// 	mlx_hook(archive.m.win, 3, 2, key_released, &(archive.key));
// 	mlx_loop_hook(archive.m.mlx, main_loop, &archive);
// 	mlx_loop(archive.m.mlx);
// 	return (0);
// }
