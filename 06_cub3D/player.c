#include "cub3D.h"

void	player_init(t_player *p, float x, float y, int color)
{
	p->pos_x = x;
	p->pos_y = y;
	p->color = color;
}

int		player_move(t_player *p, int key)
{
	if (key == KEY_A)
		p->pos_x -= 5;
	else if (key == KEY_D)
		p->pos_x += 5;
	else if (key == KEY_S)
		p->pos_y += 5;
	else if (key == KEY_W)
		p->pos_y -= 5;
	return (0);
}

void	player_draw(t_player *p, t_window *win)
{
	mlx_pixel_put(win->mlx, win->win, p->pos_x, p->pos_y, p->color);
}
