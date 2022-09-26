/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_gamedata_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:46:40 by wopark            #+#    #+#             */
/*   Updated: 2021/04/14 12:41:10 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		chk_parse_textures(t_gamedata *d)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		if (d->chk_parse[i] == 0 || d->chk_parse[i] >= 2)
			error_message("parsing", d);
	}
	return (1);
}

int		is_valid_resol(t_gamedata *d, int i)
{
	int		max_w;
	int		max_h;

	if (i != 3)
		error_message("resolution argument", d);
	mlx_get_screen_size(d->scrn.mlx, &max_w, &max_h);
	if (d->scrn.width >= max_w)
		d->scrn.width = max_w;
	if (d->scrn.height >= max_h)
		d->scrn.height = max_h;
	if (d->scrn.width < 0 || d->scrn.height < 0)
		error_message("resolution", d);
	return (0);
}

void	parse_resolution(t_gamedata *d, char **res, int n)
{
	int		i;
	int		j;

	i = 1;
	d->chk_parse[n]++;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (!ft_isdigit(res[i][j]))
				error_message("resolution arg is not digit", d);
			j++;
		}
		if (i == 1)
			d->scrn.width = ft_atoi(res[i]);
		if (i == 2)
			d->scrn.height = ft_atoi(res[i]);
		i++;
	}
	is_valid_resol(d, i);
}

int		parse_info(t_gamedata *d, char *line, char **res)
{
	if (!*line)
		return (0);
	else if ((ft_strncmp("R", res[0], ft_strlen("R")) == 0))
		parse_resolution(d, res, 0);
	else if (ft_strncmp("NO", res[0], ft_strlen("NO")) == 0)
		d->north_img = parse_texture(d, res, 1);
	else if (ft_strncmp("SO", res[0], ft_strlen("SO")) == 0)
		d->south_img = parse_texture(d, res, 2);
	else if (ft_strncmp("WE", res[0], ft_strlen("WE")) == 0)
		d->west_img = parse_texture(d, res, 3);
	else if (ft_strncmp("EA", res[0], ft_strlen("EA")) == 0)
		d->east_img = parse_texture(d, res, 4);
	else if (ft_strncmp("S", res[0], ft_strlen("S")) == 0)
		d->sprite_img = parse_texture(d, res, 5);
	else if (ft_strncmp("C", res[0], ft_strlen("C")) == 0)
		d->ceil_color = parse_color(res, d, 6);
	else if (ft_strncmp("F", res[0], ft_strlen("F")) == 0)
		d->floor_color = parse_color(res, d, 7);
	else
		return (chk_parse_textures(d));
	return (0);
}

void	parse_gamedata(t_gamedata *d, char *path)
{
	d->line = 0;
	d->map_lst = 0;
	d->chk_map_parse = 0;
	d->fd = open(path, O_RDONLY);
	chk_cubfile(d, path);
	if (d->fd < 0)
		error_message("GNL", d);
	while (1)
	{
		if ((d->eof = get_next_line(d->fd, &d->line)) < 0)
			error_message("EOF", d);
		d->res = ft_split(d->line, ' ');
		if (d->chk_map_parse == 0)
			d->chk_map_parse = parse_info(d, d->line, d->res);
		if (d->chk_map_parse == 1)
			d->chk_map_parse = parse_map(d->line, &d->map_lst);
		else if (d->chk_map_parse == 2)
			error_message("map element", d);
		free_split(d->res);
		free(d->line);
		if (d->eof == 0)
			break ;
	}
	d->scrn.map_arr = lst2arr(d, d->map_lst);
	close(d->fd);
}
