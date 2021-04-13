/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_gamedata_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:20:06 by wopark            #+#    #+#             */
/*   Updated: 2021/04/13 18:10:12 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		parse_map(char *line, t_list **map)
{
	char	*tmp;

	tmp = line;
	while (*line)
	{
		if (ft_strchr("012NEWS ", *tmp) == 0)
			return (2);
		line++;
	}
	ft_lstadd_back(map, ft_lstnew(ft_strdup(tmp)));
	return (1);
}

int		parse_color(char **res, t_gamedata *d, int n)
{
	char	*tmp;
	int		i;
	int		j;
	int		rgb;
	int		color;

	if (!res[1])
		error_message("color is empty", d);
	tmp = res[1];
	i = 0;
	j = 0;
	while (1)
	{
		printf("%s\n", res[1]);
		if (res[1][i] == ',')
		{
			tmp[j] = '\0';
			rgb = ft_atoi(tmp);
			// printf("%d\n", rgb);
			color += rgb << (2 - i) * 8;
			j = 0;
			tmp = res[1] + i + 1;
			// printf("%s\n", tmp);
		}
		else if (!res[1][i])
		{
			tmp[j] = '\0';
			rgb = ft_atoi(tmp);
			// printf("%d\n", rgb);
			color += rgb << (2 - i) * 8;
			j = 0;
			break;
		}
		i++;
		j++;
	}
	// char	**tmp;
	// int		color;
	// int		rgb;
	// int		i;

	// tmp = ft_split(res[1], ',');
	// color = 0;
	// i = 0;
	// while (tmp[i])
	// {
	// 	rgb = ft_atoi(tmp[i]);
	// 	if (rgb < 0 || rgb > 255)
	// 		error_message("color range", d);
	// 	color += rgb << ((2 - i) * 8);
	// 	i++;
	// }
	d->chk_parse[n]++;
	// free_split(tmp);
	// if (i != 3)
	// 	error_message("color argument", d);
	return (color);
}

int		get_split_size(char **res)
{
	int		ret;

	ret = 0;
	while (res[ret])
		ret++;
	return (ret);
}

int		*parse_texture(t_gamedata *d, char **res, int n)
{
	t_img	img;
	int		i;
	int		j;
	int		*ret;

	if (get_split_size(res) != 2)
		error_message("texture argument error", d);
	d->chk_parse[n]++;
	img.ptr = mlx_xpm_file_to_image(d->scrn.mlx, res[1], &img.w, &img.h);
	if (!img.ptr)
		error_message("texture file doesn't exist", d);
	img.addr = (unsigned int *)mlx_get_data_addr(img.ptr, &img.bpp,
	&img.size_line, &img.endian);
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
