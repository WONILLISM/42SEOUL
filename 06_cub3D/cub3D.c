#include "cub3D_window.h"
#include "cub3D_player.h"

int		g_map[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int		key_pressed(int key, t_window *win)
{
	if (key == _W || key == _A || key == _S || key == _D)
		player_move(win, key);
	else if (key == _ESC)
		exit(0);
	return (0);
}

int		main_loop(t_window *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	set_grid(win);
	player_draw(win);
	return (0);
}

int		main(void)
{
	t_window win;
	t_player player;

	win.p = &player;
	window_init(&win, 500, 500);
	player_init(&win, 250, 250, 0);
	mlx_loop_hook(win.mlx_ptr, main_loop, &win);
	mlx_hook(win.win_ptr, 2, 0, key_pressed, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
