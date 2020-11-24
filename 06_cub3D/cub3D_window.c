#include "cub3D_window.h"

extern	int	g_map[10][10];

void	window_init(t_window *win, int w, int h)
{
	win->width = w;
	win->height = h;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, w, h, "cub3D");
}

void	*create_square(int x1, int y1, int x2, int y2, int fill)
{
	void	*obj;
}

void	set_grid(t_window *win)
{
	int		i;
	int		j;
	void	*box;
	int		*addr;
	int		tmp[3];

	box = mlx_new_image(win->mlx_ptr, win->width/10, win->height/10);
	addr = mlx_get_data_addr(box, &tmp[0], &tmp[1], &tmp[2]);
	i = 0;
	while (i < win->width / 10)
	{
		j = 0;
		while (j < win->height / 10)
		{
			addr[i * win->width / 10 + j] = 0xffffff;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, box, 0, 0);
}
