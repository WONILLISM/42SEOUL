#include "cub3d.h"

int		g_map[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,1,1,2,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,2,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,1,1,1,2,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

void	init_window(t_archive *a)
{
	a->width = 500;
	a->height = 500;
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
void	init_player(t_player *p)
{
	p->pos.x = 75;
	p->pos.y = 75;
	p->move_speed = 2;
	p->rot_speed = 2.5;
	p->dir.x = 1;
	p->dir.y = 0;
}

void	init_screen(t_screen *s)
{
	s->plane.x = 0;
	s->plane.y = 0.6;
	s->delta.x = 0;
	s->delta.y = 0;
	s->ray.x = 0;
	s->ray.y = 0;
	s->side.x = 0;
	s->side.y = 0;
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
	return (0);
}

void	move_player(t_archive *a)
{
	t_vec	np;
	t_vec	nd;

	if (a->key.w)
	{
		np = add_vector(a->p.pos, mul_vector(a->p.dir, a->p.move_speed));
		if (g_map[(int)a->p.pos.y][(int)np.x] == 0) 
			a->p.pos.x = np.x;
		if (g_map[(int)np.y][(int)a->p.pos.x] == 0)
			a->p.pos.y = np.y;
	}
	else if (a->key.s)
	{
		np = add_vector(a->p.pos, mul_vector(a->p.dir, -1 * a->p.move_speed));
		if (g_map[(int)a->p.pos.y][(int)np.x] == 0)
			a->p.pos.x = np.x;
		if (g_map[(int)np.y][(int)a->p.pos.x] == 0)
			a->p.pos.y = np.y;
	}
	else if (a->key.a)
	{		
		a->p.dir = rot_vector(a->p.dir, -1 * a->p.rot_speed);
		a->s.plane = rot_vector(a->s.plane, -1 * a->p.rot_speed);
	}
	else if (a->key.d)
	{
		a->p.dir = rot_vector(a->p.dir, a->p.rot_speed);
		a->s.plane = rot_vector(a->s.plane, a->p.rot_speed);
	}
}

t_img	create_square(t_archive *a, int w, int h, int fill)
{
	int		i;
	int		j;
	t_img	ret;

	ret.ptr = mlx_new_image(a->m.mlx, w, h);
	ret.addr = (unsigned int *)mlx_get_data_addr(ret.ptr, &ret.bpp, &ret.size_line, &ret.endian);

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
			ret.addr[i * w + j] = fill;
	}
	return ret;
}

void	draw_grid(t_archive *a)
{
	t_img	wall;
	t_img	door;
	t_img	ground;
	int		row_size;
	int		col_size;
	int		i;
	int		j;

	row_size = a->height/10;
	col_size = a->width/10;
	wall = create_square(a, col_size-1, row_size-1, 0x2e3258);
	door = create_square(a, col_size-1, row_size-1, 0x653865);
	ground = create_square(a, col_size-1, row_size-1, 0x222222);
	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			if (g_map[i][j] == 1)
				mlx_put_image_to_window(a->m.mlx, a->m.win, wall.ptr, j * col_size, i * row_size);
			else if(g_map[i][j] == 2)
				mlx_put_image_to_window(a->m.mlx, a->m.win, door.ptr, j * col_size, i * row_size);
			else if(g_map[i][j] == 0)
				mlx_put_image_to_window(a->m.mlx, a->m.win, ground.ptr, j * col_size, i * row_size);
	}
}

void	draw_rays(t_archive *a)
{
	double	nx; 
	double	ny;
	double	i;
	int		j;
	int		hit;
	int		mapX;
	int		mapY;
	t_vec	ray_dir;

	i = -0.68;
	while (i <= 0.68)
	{
		ray_dir.x = a->p.dir.x + i*a->s.plane.x;
		ray_dir.y = a->p.dir.y + i*a->s.plane.y;
		j = 0;
		while (1)
		{
			nx = a->p.pos.x + j * ray_dir.x;
			ny = a->p.pos.y + j * ray_dir.y;
			mapX = (int)nx;
			mapY = (int)ny;

			if (g_map[mapY/50][mapX/50])
				break;
			mlx_pixel_put(a->m.mlx, a->m.win, nx, ny, 0xffff00);
			j++;
		}
		i += 0.03;
	}
}
void	ray_cast(t_archive *a)
{
	int		x;
	int		mapX;
	int		mapY;
	int		px;
	int		py;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	perpWallDist;

	x = 0;
	while (x < a->width)
	{
		a->s.screenX =  2 * (x / (double)a->width) - 1;
		a->s.ray.x = a->p.dir.x + a->s.plane.x * a->s.screenX;
		a->s.ray.y = a->p.dir.y + a->s.plane.y * a->s.screenX;
		mapX = (int)(a->p.pos.x) / 50;
		mapY = (int)(a->p.pos.y) / 50;
		a->s.delta.x = abs(1 / a->s.ray.x);
		a->s.delta.y = abs(1 / a->s.ray.y);

		if (a->s.ray.x < 0)
		{
			stepX = -1;
			a->s.side.x = (a->p.pos.x - mapX) * a->s.delta.x;
		}
		else
		{
			stepX = 1;
			a->s.side.x = (mapX + 1.0) * a->s.delta.x;
		}
		if (a->s.ray.y < 0)
		{
			stepY = -1;
			a->s.side.x = (a->p.pos.y - mapY) * a->s.delta.y;
		}
		else
		{
			stepY = 1;
			a->s.side.y = (mapY + 1.0) * a->s.delta.y;
		}

		while (!hit)
		{
			if (a->s.side.x < a->s.side.y)
			{
				a->s.side.x += a->s.delta.x;
				mapX += stepX;
				side = 0;
			}
			else
			{
				a->s.side.y += a->s.delta.y;
				mapY += stepY;
				side = 1;
			}
			if (g_map[mapX][mapY] > 0) 
				hit = 1;
		}
		x++;
	}
}

void	draw_player(t_archive *a)
{
	t_img	img1;

	img1 = create_square(a, 5, 5, 0xffff00);
	mlx_put_image_to_window(a->m.mlx, a->m.win, img1.ptr, a->p.pos.x - 2, a->p.pos.y - 2);	
}

int		main_loop(t_archive *a)
{
	mlx_clear_window(a->m.mlx, a->m.win);
	draw_grid(a);
	draw_player(a);
	draw_rays(a);
	// ray_cast(a);
	move_player(a);
	return (0);
}

int	 main(void)
{
	t_archive	archive;

	init_window(&archive);
	init_player(&archive.p);
	init_screen(&archive.s);

	mlx_hook(archive.m.win, 2, 1, key_pressed, &(archive.key));
	mlx_hook(archive.m.win, 3, 2, key_released, &(archive.key));
	mlx_loop_hook(archive.m.mlx, main_loop, &archive);
	mlx_loop(archive.m.mlx);
	return (0);
}