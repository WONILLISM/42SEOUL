#include "cub3D_var.h"

// t_img	*create_square(t_archive *arcv, int w, int h, int fill)
// {
// 	t_img	*ret;
// 	int		i;
// 	int		j;

// 	if (!(ret = (t_img *)malloc(sizeof(t_img))))
// 		return (NULL);
// 	ret->w = w;
// 	ret->h = h;
// 	ret->ptr = mlx_new_image(arcv->screen->mlx, ret->w, ret->h);
// 	ret->obj_addr = (int *)mlx_get_data_addr(ret->ptr,
// 	&ret->bit_per_pixel, &ret->size_line, &ret->endian);
// 	i = -1;
// 	while (++i < ret->h)
// 	{
// 		j = -1;
// 		while (++j < ret->w)
// 			ret->obj_addr[i * ret->w + j] = fill;
// 	}
// 	return (ret);
// }
