#include "../../includes/cub3d.h"

int		chk_parse_textures(t_gamedata *d)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		if (d->chk_parse[i] == 0 || d->chk_parse[i] >= 2)
			return (0);
	}
	return (1);
}

int		is_valid_resol(t_gamedata *d)
{
	int		max_w;
	int		max_h;

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
				error_message("resolution is not digit", d);
			j++;
		}
		if (i == 1)
			d->scrn.width = ft_atoi(res[i]);
		if (i == 2)
			d->scrn.height = ft_atoi(res[i]);
		i++;
	}
	if (i <= 2 || i >= 4)
		error_message("resolution", d);
	is_valid_resol(d);
}

int		parse_info(t_gamedata *d, char *line, char **res)
{
	if (!*line)
		return (0);
	else if ((ft_strncmp("R", res[0],ft_strlen("R")) == 0))
		parse_resolution(d, res, 0);
	else if (ft_strncmp("NO", res[0], ft_strlen("NO")) == 0)
		d->north_img = parse_texture(d, res[1], 1);
	else if (ft_strncmp("SO", res[0], ft_strlen("SO")) == 0)
		d->south_img = parse_texture(d, res[1], 2);
	else if (ft_strncmp("WE", res[0], ft_strlen("WE")) == 0)
		d->west_img = parse_texture(d, res[1], 3) ;
	else if (ft_strncmp("EA", res[0], ft_strlen("EA")) == 0)
		d->east_img = parse_texture(d, res[1], 4);
	else if (ft_strncmp("S", res[0], ft_strlen("S")) == 0)
		d->sprite_img = parse_texture(d, res[1], 5);
	else if (ft_strncmp("C", res[0], ft_strlen("C")) == 0)
		d->ceil_color = parse_color(res, d, 6);
	else if (ft_strncmp("F", res[0], ft_strlen("F")) == 0)
		d->floor_color = parse_color(res, d, 7);
	else
	{
		if (chk_parse_textures(d))
			return (1);
		else
			error_message("parsing", d);
	}
	return (0);
}

int		parse_gamedata(t_gamedata *d, char *path)
{
	int			fd;
	int			eof;
	int			chk_map_parse;
	char		*line;
	char		**res;
	t_list		*map_lst;

	line = 0;
	map_lst = 0;
	chk_map_parse = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_message("GNL", d);
	while (1)
	{
		if ((eof = get_next_line(fd, &line)) < 0)
			error_message("EOF", d);
		res = ft_split(line, ' ');
		if (chk_map_parse == 0)
			chk_map_parse = parse_info(d, line, res);
		if (chk_map_parse == 1)
			chk_map_parse = parse_map(line, &map_lst);
		else if (chk_map_parse == 2)
		{
			free(line);
			error_message("map element", d);
			break;
		}
		else if (chk_map_parse == 3)
		{
			eof = 0;
		}
		free(line);
		if (eof == 0)
			break ;
	}
	d->scrn.map_arr = lst2arr(d, map_lst);
	close(fd);
	return (0);	// no error
}
