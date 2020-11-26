#include "cub3D_window.h"

extern	int	g_map[10][10];

void	window_init(t_window *win, int w, int h)
{
	win->width = w;
	win->height = h;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, w, h, "cub3D");
}

void	set_map(t_window *win)
{
	void	*sq;
	int		row_size;
	int		col_size;
	int		i;
	int		j;

	row_size = win->height / 10;
	col_size = win->width / 10;
	i = 0;
	sq = create_square(win, row_size, col_size, 0xffffff);
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (g_map[i][j])
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, sq, j * col_size, i * row_size);
			j++;
		}
		i++;
	}
}

