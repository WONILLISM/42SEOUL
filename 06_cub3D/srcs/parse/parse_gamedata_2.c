#include "../../includes/cub3d.h"

void	parse_map(char *line, t_list **map)
{
	char	*tmp;

	tmp = line;
	while (*line)
	{
		if (ft_strchr("012NEWS ", *tmp) == 0)
		{
			printf("Wrong map element\n");	// map element error
			break;
		}
		line++;
	}
	ft_lstadd_back(map, ft_lstnew(ft_strdup(tmp)));
}

int		parse_color(char **res)
{
	char	**tmp;
	int		color;
	int		rgb;
	int		i;

	tmp = ft_split(res[1], ',');
	color = 0;
	i = -1;
	while (++i < 3)
	{
		rgb = ft_atoi(tmp[i]);
		if (rgb < 0 || rgb > 255)
			return (-1);
		color += rgb << ((2 - i) * 8);
	}
	free_split(tmp);
	if (i <= 2 || i >= 4)
		return (-1);	// color parsing error
	return (color);
}

int		*parse_texture(t_gamedata *d, char *path)
{
	t_img	img;
	int		i;
	int		j;
	int		*ret;

	img.ptr = mlx_xpm_file_to_image(d->scrn.mlx, path, &img.w, &img.h);
	img.addr = (unsigned int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	ret = (int *)malloc(sizeof(int) * img.w * img.h);
	i = -1;
	while (++i < img.h)
	{
		j = -1;
		while (++j < img.w)
			ret[img.w * i + j] = img.addr[img.w * i + j];
	}
	mlx_destroy_image(d->scrn.mlx, img.ptr);
	return (ret);
}