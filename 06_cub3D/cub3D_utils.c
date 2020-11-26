#include "cub3D_var.h"

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
