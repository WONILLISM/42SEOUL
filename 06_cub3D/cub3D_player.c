#include "cub3D_player.h"

extern int	g_map[MAP_HEIGHT][MAP_WIDTH];

void	player_init(t_window *win)
{
	// player 초기 위치 벡터
	win->p->pos_x = 22;
	win->p->pos_y = 12;
	// player 초기 방향 벡터
	win->p->dir_x = -1;
	win->p->dir_y = 0;
	// player 카메라 평면
	win->p->c_plane_x = 0;
	win->p->c_plane_y = 0.66f;
	// 현재 프레임, 이전 프레임
	win->p->cur_frame = 0;
	win->p->prev_frame = 0;
	player_draw(win);
}

void	player_draw(t_window *win)
{
	void	*p_img;
	float	x;
	float	y;
	float	radius;
	float	angle;
	int		len;
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
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0xaaffff00);
			len += 1;
			if ((win->p->dir >= 360) || (win->p->dir <= -360))
				win->p->dir = 0;
			if (g_map[((int)y)/50][((int)x)/50])
				break;
			if (!(x >= 0 && x <= win->width) || !(y >= 0 && y <= win->height))
				break;
		}
		sight -= 1.0;
	}
	p_img = create_square(win, 5, 5, 0xffff00);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, p_img, win->p->pos_x - 2.5, win->p->pos_y - 2.5);
}

void	player_move(t_window *win, int key)
{
	int	dx;
	int	dy;
	if (key == _W)
	{
		dx = win->p->pos_x + 5 * cos(win->p->dir * DEG2RAD);
		dy = win->p->pos_y + 5 * sin(win->p->dir * DEG2RAD);
		if (dx < 0 || dx >= win->width || dy < 0 || dy >= win->height || g_map[dy/50][dx/50])
			return;
		win->p->pos_x = dx;
		win->p->pos_y = dy;
	}
	else if (key == _S)
	{
		dx = win->p->pos_x - 5 * cos(win->p->dir * DEG2RAD);
		dy = win->p->pos_y - 5 * sin(win->p->dir * DEG2RAD);
		if (dx < 0 || dx >= win->width || dy < 0 || dy >= win->height || g_map[dy/50][dx/50])
			return;
		win->p->pos_x = dx;
		win->p->pos_y = dy;
	}
	else if (key == _A)
		win->p->dir -= 5;
	else if (key == _D)
		win->p->dir += 5;
}
