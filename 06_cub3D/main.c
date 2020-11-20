#include "cub3D.h"

void	init_window(t_player *p, t_window *win, int w, int h)
{
	win->width = w;
	win->height = h;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->width, win->height, "test");

	mlx_clear_window(win->mlx, win->win);
	player_init(p, 250, 250, 0xff0000);
}

int		terminate_window(void)
{
	write(1, "window is terminated.\n", 23);
	exit(0);
	return (0);
}

int		key_parsing(t_player *p, t_window *win, int key, void *param)
{
	if (key == 53 && param)
		return (terminate_window());
	else if (((key >= 0 && key <= 2) || key == 13) && param)
		return (player_move(p, key));
	player_draw(p, win);
	return (-1);
}

int		main(void)
{
	t_window	win;
	t_player	player;

	init_window(&player, &win, 500, 500);
	player_draw(&player, &win);
	mlx_key_hook(win.win, key_parsing, &win);
	mlx_loop(win.mlx);
	return (0);
}
