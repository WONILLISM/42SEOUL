#include "../../includes/cub3d.h"

int		parse_map(char *line, t_list **map)
{
	char	*tmp;

	tmp = line;
	if (!*line)
		return (3);
	while (*line)
	{
		if (ft_strchr("012NEWS ", *tmp) == 0)
		{
			return (2);
		}
		line++;
	}
	ft_lstadd_back(map, ft_lstnew(ft_strdup(tmp)));
	return (1);
}

int		parse_color(char **res, t_gamedata *d, int n)
{
	char	**tmp;
	int		color;
	int		rgb;
	int		i;

	tmp = ft_split(res[1], ',');
	color = 0;
	d->chk_parse[n]++;
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

int		*parse_texture(t_gamedata *d, char *path, int n)
{
	t_img	img;
	int		i;
	int		j;
	int		*ret;

	d->chk_parse[n]++;
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
