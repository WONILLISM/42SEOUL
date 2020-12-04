#include "cub3D_player.h"

extern int	g_map[10][10];

void	player_init(t_window *win, int x, int y, int dir)
{
	win->p->pos_x = x;
	win->p->pos_y = y;
	win->p->dir = dir;
	player_draw(win);
}

void	player_draw(t_window *win)
{
	float	x;
	float	y;
	float	radius;
	float	angle;
	float	len;
	float	sight;

	radius = 3.0f;
	sight = 10.0f;
	while (sight >= -10.0f)
	{
		len = 0.0f;
		while (1)
		{
			x = cos((win->p->dir + sight) * DEG2RAD) * len + win->p->pos_x;
			y = sin((win->p->dir + sight) * DEG2RAD) * len + win->p->pos_y;
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0x00ffff);
			len += 0.1;
			if ((win->p->dir >= 360) || (win->p->dir <= -360))
				win->p->dir = 0;
			if (g_map[((int)y)/50][((int)x)/50])
				break;
			if (!(x >= 0 && x <= win->width) || !(y >= 0 && y <= win->height))
				break;
		}
		sight -= 1.0;
	}
	while (radius >= 0)
	{
		angle = 0.0f;
		while (angle <= 360)
		{
			x = cos(angle * DEG2RAD) * radius + win->p->pos_x;
			y = sin(angle * DEG2RAD) * radius + win->p->pos_y;
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y,0xffff00);
			angle += 0.5;
		}
		radius -= 0.5;
	}
}

void	player_move(t_window *win, int key)
{
	if (key == _W)
	{
		win->p->pos_x += 5 * cos(win->p->dir * DEG2RAD);
		win->p->pos_y += 5 * sin(win->p->dir * DEG2RAD);
	}
	else if (key == _S)
	{
		win->p->pos_x -= 5 * cos(win->p->dir * DEG2RAD);
		win->p->pos_y -= 5 * sin(win->p->dir * DEG2RAD);
	}
	else if (key == _A)
		win->p->dir -= 5;
	else if (key == _D)
		win->p->dir += 5;
}
