#include "../includes/cub3d.h"

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
	int		mapSizeX;
	int		mapSizeY;

	mapSizeX = a->width/4;
	mapSizeY = a->height/4;
	i = 0;
	while (i <= mapSizeY){
		j = 0;
		while (j <= mapSizeX){
			if (i % (mapSizeY/10) != 0 && j % (mapSizeY/10) != 0){
				if (a->map[(int)(i/(mapSizeY/10))][(int)(j/(mapSizeX/10))] == '1'){
					if (!a->s.view.addr[(a->width) * i + j])
						a->s.view.addr[(a->width) * i + j] = 0x2e3258;
					else
						a->s.view.addr[(a->width) * i + j] += 0x44000000;
				}
				else if (a->map[(int)(i/(mapSizeY/10))][(int)(j/(mapSizeX/10))] == '2'){
					if (!a->s.view.addr[(a->width) * i + j])
						a->s.view.addr[(a->width) * i + j] = 0x653865;
					else
						a->s.view.addr[(a->width) * i + j] += 0x44000000;
				}
				else
					a->s.view.addr[(a->width) * i + j] = 0x222222;
			}
			else{
				if (!a->s.view.addr[(a->width) * i + j])
					a->s.view.addr[(a->width) * i + j] = 0x000000;
				// else
					// a->s.view.addr[(a->width) * i + j] = 0xffffff;
			}
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

int		check_hit(t_archive *a)
{
	int color;

	a->s.delta.x = fabs(1 / a->s.ray.x);
	a->s.delta.y = fabs(1 / a->s.ray.y);
	a->s.isHitWall = 0;
	loop_to_wall(a);
	if (!a->s.isHitSide)
	{
		if (a->s.ray.x > 0)		//동
			color = 0xb35f44;
		else					//서
			color = 0xfeae51;
		a->s.distWall = (a->s.gridX - a->p.pos.x + (1 - a->s.cellX) / 2 ) / a->s.ray.x;
	}
	else
	{
		if (a->s.ray.y > 0)		//남
			color = 0x98b2d1;
		else					//북
			color = 0x3078b4;
		a->s.distWall = (a->s.gridY - a->p.pos.y + (1 - a->s.cellY) / 2 ) / a->s.ray.y;
	}
	return (color);
}
void	proc_dda(t_archive *a, int x)
{
	// 화면의 범위를 -1 ~ 1로 바꿈
	a->s.screenX = 2 * x / (double)a->width - 1;
	// 광선 벡터를 구하는 과정
	a->s.ray = add_vector(a->p.dir, mul_vector(a->s.plane, a->s.screenX));
	// 현재 플레이어가 지도(g_map) 칸 안에 있는지 확인하기 위함
	a->s.gridX = (int)(a->p.pos.x);
	a->s.gridY = (int)(a->p.pos.y);
	// dda과정
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
void	ray_cast(t_archive *a)
{
	int		x;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;

	x = 0;
	while (x < a->width)
	{
		proc_dda(a, x);
		color = check_hit(a);
		lineHeight = (int)(a->height / a->s.distWall);
		drawStart = -lineHeight / 2 + a->height / 2;
		drawEnd = lineHeight / 2 + a->height / 2;
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= a->height)
			drawEnd = a->height - 1;
		while (drawStart < drawEnd)
		{
			a->s.view.addr[a->width * (drawStart++) + x] = color;
		}
		x++;
	}
}

int		main_loop(t_data *d)
{
	mlx_clear_window(d->a.m.mlx, d->a.m.win);
	d->a.s.view.ptr = mlx_new_image(d->a.m.mlx, d->a.width, d->a.height);
	d->a.s.view.addr = (unsigned int *)mlx_get_data_addr(d->a.s.view.ptr, &(d->a.s.view.bpp), &(d->a.s.view.size_line), &(d->a.s.view.endian));
	set_floor_ceil(d);
	ray_cast(&d->a);
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
