#include "cub3d.h"

int		g_map[16][16] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,1,1,0,0,0,0,1,1,1,1,0,1},
	{1,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	init_window(t_archive *a)
{
	a->width = 1024	;
	a->height = 512;
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
	p->pos.x = 250;
	p->pos.y = 250;
	p->angle = 0.0f;
	p->delta.x = cos(p->angle);
	p->delta.y = sin(p->angle);
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
	if (a->key.w)
	{
		a->p.pos.x += a->p.delta.x;
		a->p.pos.y += a->p.delta.y;
	}
	else if (a->key.s)
	{
		a->p.pos.x += a->p.delta.x;
		a->p.pos.y += a->p.delta.y;
	}
	else if (a->key.a)
	{
		a->p.angle -= 0.1;
		if (a->p.angle < 0)
			a->p.angle = 2*PI;
		a->p.delta.x = cos(a->p.angle)*2;
		a->p.delta.y = sin(a->p.angle)*2;
	}
	else if (a->key.d)
	{
		a->p.angle += 0.1;
		if (a->p.angle > 2*PI)
			a->p.angle = 0;
		a->p.delta.x = cos(a->p.angle)*2;
		a->p.delta.y = sin(a->p.angle)*2;
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

void	draw_map(t_archive *a)
{
	t_img	wall;
	t_img	ground;
	int		row_size;
	int		col_size;
	int		i;
	int		j;

	row_size = a->height/16;
	col_size = (a->width/2)/16;
	wall = create_square(a, col_size-1, row_size-1, 0xffffff);
	ground = create_square(a, col_size-1, row_size-1, 0x777777);
	i = -1;
	while (++i < 16)
	{
		j = -1;
		while (++j < 16)
			if (g_map[i][j])
				mlx_put_image_to_window(a->m.mlx, a->m.win, wall.ptr, j * col_size, i * row_size);
			else
				mlx_put_image_to_window(a->m.mlx, a->m.win, ground.ptr, j * col_size, i * row_size);
	}
}

void	draw_rays(t_archive *a)
{
	double	nx;
	double	ny;
	int	i;

	i = 0;
	while (1){
		nx = a->p.pos.x + i * a->p.delta.x;
		ny = a->p.pos.y + i * a->p.delta.y;
		if (nx < 0 || ny < 0 || nx > 512 || ny > 512)
			break;
		mlx_pixel_put(a->m.mlx, a->m.win, nx, ny, 0xffff00);
		i++;
	}
}

void	draw_player(t_archive *a)
{
	t_img	img1;

	img1 = create_square(a, 5, 5, 0xffff00);
	mlx_put_image_to_window(a->m.mlx, a->m.win, img1.ptr, a->p.pos.x -2, a->p.pos.y-2);	
}

int		main_loop(t_archive *a)
{
	mlx_clear_window(a->m.mlx, a->m.win);
	draw_map(a);
	draw_player(a);
	draw_rays(a);
	move_player(a);
	return (0);
}

int	 main(void)
{
	t_archive	archive;

	init_window(&archive);
	init_player(&archive.p);

	mlx_hook(archive.m.win, 2, 1, key_pressed, &(archive.key));
	mlx_hook(archive.m.win, 3, 2, key_released, &(archive.key));
	mlx_loop_hook(archive.m.mlx, main_loop, &archive);
	mlx_loop(archive.m.mlx);
	return (0);
}