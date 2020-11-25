#include "cub3D_window.h"

extern	int	g_map[10][10];

void	window_init(t_window *win, int w, int h)
{
	win->width = w;
	win->height = h;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, w, h, "cub3D");
}

void	*create_square(t_window *win, int w, int h, int fill)
{
	void	*obj;
	int		*addr;
	int		tmp[3];
	int		i;
	int		j;

	obj = mlx_new_image(win->mlx_ptr, w, h);
	addr = (int *)mlx_get_data_addr(obj, &tmp[0], &tmp[1], &tmp[2]);
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
			addr[i * w + j] = fill;
	}
	return (obj);
}

void	set_grid(t_window *win)
{
	void	*sq;
	int		row_size;
	int		col_size;
	int		i;
	int		j;

	row_size = win->height / 10;
	col_size = win->width / 10;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (g_map[i][j]){
				sq = create_square(win, row_size, col_size, 0xffffff);
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, sq, j * col_size, i * row_size);
			}
			j++;
		}
		i++;
	}
}

