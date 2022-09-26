/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_gamedata_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:20:06 by wopark            #+#    #+#             */
/*   Updated: 2021/04/14 12:37:58 by wopark           ###   ########.fr       */
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

int		proc_color(char **res, t_gamedata *d, t_color *c)
{
	if (c->rgb < 0 || c->rgb > 255)
		error_message("color range", d);
	c->color += c->rgb << ((2 - c->cnt) * 8);
	c->rgb = 0;
	c->cnt++;
	if (*(c->tmp) == '\0')
	{
		if (*((c->tmp) - 1) == ',')
			error_message("color argument", d);
		return (1);
	}
	return (0);
}

int		parse_color(char **res, t_gamedata *d, int n)
{
	t_color		c;

	c.tmp = res[1];
	c.rgb = 0;
	c.cnt = 0;
	c.color = 0;
	if (!res[1])
		error_message("color is empty", d);
	while (1)
	{
		if (ft_isdigit(*(c.tmp)))
			c.rgb = c.rgb * 10 + (*(c.tmp) - '0');
		else if (*(c.tmp) == ',' || *(c.tmp) == '\0')
		{
			if (proc_color(res, d, &c) == 1)
				break ;
		}
		(c.tmp)++;
	}
	if (c.cnt != 3)
		error_message("color argument", d);
	d->chk_parse[n]++;
	return (c.color);
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
