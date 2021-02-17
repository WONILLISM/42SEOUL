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

// int		g_map[10][10] = {
// 	{1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1}
// };

void	init_window(t_archive *a)
{
	a->width = 1000;
	a->height = 1000;
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
	p->pos.x = 1.5f;
	p->pos.y = 1.5f;
	p->move_speed = 0.05f;
	p->rot_speed = 0.02f;
	p->dir.x = 0.0f;
	p->dir.y = 1.0f;
}

void	init_screen(t_screen *s)
{
	s->plane.x = -0.6f;
	s->plane.y = 0.0f;
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
		if (g_map[(int)(a->p.pos.y)][(int)(np.x)] != 1) 
			a->p.pos.x = np.x;
		if (g_map[(int)(np.y)][(int)(a->p.pos.x)] != 1)
			a->p.pos.y = np.y;
	}
	else if (a->key.s)
	{
		np = add_vector(a->p.pos, mul_vector(a->p.dir, -1 * a->p.move_speed));
		if (g_map[(int)(a->p.pos.y)][(int)(np.x)] != 1)
			a->p.pos.x = np.x;
		if (g_map[(int)(np.y)][(int)(a->p.pos.x)] != 1)
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
	int		i;
	int		j;
	int		mapSizeX;
	int		mapSizeY;

	mapSizeX = a->width/4;
	mapSizeY = a->height/4; 
	i = 0;
	while (i <= mapSizeY){
		j = 0;
		while (j <= mapSizeX){
			if (i % (mapSizeY/10) != 0 && j % (mapSizeY/10) != 0){
				if (g_map[(int)(i/(mapSizeY/10))][(int)(j/(mapSizeX/10))] == 1){
					// if (!a->s.view.addr[(a->width) * i + j])
						a->s.view.addr[(a->width) * i + j] = 0x2e3258;
					// else 
					// 	a->s.view.addr[(a->width) * i + j] = 0x222222;
				}
				else if (g_map[(int)(i/(mapSizeY/10))][(int)(j/(mapSizeX/10))] == 2){
					// if (!a->s.view.addr[(a->width) * i + j])
						a->s.view.addr[(a->width) * i + j] = 0x653865;
					// else 
					// 	a->s.view.addr[(a->width) * i + j] = 0x111111;
					// a->s.view.addr[(a->width) * i + j] = 0x653865;			
				}
				else
					a->s.view.addr[(a->width) * i + j] = 0x222222;
			}
			else
				a->s.view.addr[(a->width) * i + j] = 0x444444;
			j++;
		}
		i++;
	}
	i = -1;
	while (i < 2){
		j = -1;
		while (j < 2){
			a->s.view.addr[(a->width) * (int)(a->p.pos.y/10 * mapSizeY + i) + (int)(a->p.pos.x/10 * mapSizeX + j)] = 0xffff00;
			j++;
		}
		i++;
	}
}

// void	draw_rays(t_archive *a)
// {
// 	double	nx; 
// 	double	ny;
// 	double	i;
// 	int		j;
// 	int		hit;
// 	int		mapX;
// 	int		mapY;
// 	t_vec	ray_dir;

// 	i = -0.25;
// 	while (i <= 0.25)
// 	{
// 		ray_dir.x = a->p.dir.x + i*a->s.plane.x;
// 		ray_dir.y = a->p.dir.y + i*a->s.plane.y;
// 		j = 0;
// 		while (1)
// 		{
// 			nx = a->p.pos.x + j * ray_dir.x;
// 			ny = a->p.pos.y + j * ray_dir.y;
// 			mapX = (int)nx;
// 			mapY = (int)ny;

// 			if (g_map[mapY/50][mapX/50])
// 				break;
// 			a->s.view.addr[a->width * mapY + mapX] = 0xffff00;
// 			// mlx_pixel_put(a->m.mlx, a->m.win, nx, ny, 0xffff00);
// 			j++;
// 		}
// 		i += 0.01;
// 	}
// }

// void	draw_player(t_archive *a)
// {
// 	t_img	img1;

// 	img1 = create_square(a, 5, 5, 0xffff00);
// 	mlx_put_image_to_window(a->m.mlx, a->m.win, img1.ptr, a->p.pos.x - 2, a->p.pos.y - 2);	
// }

void	ray_cast(t_archive *a)
{
	int		x;
	int		gridX;
	int		gridY;
	int		cellX;
	int		cellY;
	int		side;
	int		isHitWall;
	double	perpWall;
	
	// a->s.view.ptr = mlx_new_image(a->m.mlx, a->width, a->height);
	// a->s.view.addr = (unsigned int *)mlx_get_data_addr(a->s.view.ptr, &(a->s.view.bpp), &(a->s.view.size_line), &(a->s.view.endian));

	x = 0;
	while (x < a->width)
	{
		a->s.screenX = 2 * x / (double)a->width - 1;
		a->s.ray.x = a->p.dir.x + a->s.plane.x * a->s.screenX;
		a->s.ray.y = a->p.dir.y + a->s.plane.y * a->s.screenX;
		gridX = (int)(a->p.pos.x);
		gridY = (int)(a->p.pos.y);
		a->s.delta.x = fabs(1 / a->s.ray.x);
		a->s.delta.y = fabs(1 / a->s.ray.y);
		isHitWall = 0;

		if (a->s.ray.x < 0)
		{
			cellX = -1;
			a->s.side.x = (a->p.pos.x - gridX) * a->s.delta.x;
		}
		else
		{
			cellX = 1;
			a->s.side.x = (gridX + 1.0f - a->p.pos.x) * a->s.delta.x;
		}

		if (a->s.ray.y < 0)
		{
			cellY = -1;
			a->s.side.y = (a->p.pos.y - gridY) * a->s.delta.y;
		}
		else
		{
			cellY = 1;
			a->s.side.y = (gridY + 1.0f - a->p.pos.y) * a->s.delta.y;
		}
		while (!isHitWall)
		{
			if (a->s.side.x < a->s.side.y)
			{
				a->s.side.x += a->s.delta.x;
				gridX += cellX;
				side = 0;
			}
			else
			{
				a->s.side.y += a->s.delta.y;
				gridY += cellY;
				side = 1;
			}
			if (g_map[gridY][gridX]==1)
				isHitWall = 1;
		}
		int color;
		color = 0xffffff;
		if (!side)
		{
			if ((a->s.ray.x < 0 && a->s.ray.y > 0) || (a->s.ray.x < 0 && a->s.ray.y < 0))
				color = 0xb35f44;
			else
				color = 0xfeae51;
			perpWall = (gridX - a->p.pos.x + (1 - cellX) / 2 ) / a->s.ray.x;
		}
		else
		{
			if ((a->s.ray.x > 0 && a->s.ray.y < 0) || (a->s.ray.x < 0 && a->s.ray.y < 0))
				color = 0x98b2d1;
			else 
				color = 0xb3078b4;
			perpWall = (gridY - a->p.pos.y + (1 - cellY) / 2 ) / a->s.ray.y;
		}
		
		int		lineHeight = (int)(a->height / perpWall);

		int		drawStart = -lineHeight / 2 + a->height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int		drawEnd = lineHeight / 2 + a->height / 2;
		if (drawEnd >= a->height)
			drawEnd = a->height - 1;
		// if (side == 1)
		// 	color /= 2;
		while (drawStart < drawEnd)
		{
			a->s.view.addr[a->width * (drawStart++) + x] = color;
		}
		x++;
	}
	// mlx_put_image_to_window(a->m.mlx, a->m.win, a->s.view.ptr, 0, 0);
}


int		main_loop(t_archive *a)
{
	mlx_clear_window(a->m.mlx, a->m.win);
	a->s.view.ptr = mlx_new_image(a->m.mlx, a->width, a->height);
	a->s.view.addr = (unsigned int *)mlx_get_data_addr(a->s.view.ptr, &(a->s.view.bpp), &(a->s.view.size_line), &(a->s.view.endian));
	// draw_player(a);
	// draw_rays(a);
	ray_cast(a);
	if (a->key.z == 1)
		draw_map(a);
	move_player(a);
	mlx_put_image_to_window(a->m.mlx, a->m.win, a->s.view.ptr, 0, 0);
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