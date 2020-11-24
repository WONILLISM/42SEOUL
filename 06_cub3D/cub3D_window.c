#include "cub3D_window.h"

void	window_init(t_window *win, int w, int h)
{
	win->width = w;
	win->height = h;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, w, h, "cub3D");
}

void	set_grid(t_window *win)
{
	int		row;
	int		col;

	row = 0;
	while (row <= win->height)
	{
		row += win->height / 10;
		col = 0;
		while (col <= win->width)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, row, col, 0xffffff);
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, col, row, 0xffffff);
			col++;
		}
	}
}
