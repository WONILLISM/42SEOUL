#include "../../includes/cub3d.h"

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
		printf("resolution error\n");
	return (0);
}

void	parse_resolution(t_gamedata *d, char **res)
{
	int		i;
	int		j;

	i = 1;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (!ft_isdigit(res[i][j]))
				printf("is not digit\n");
			j++;
		}
		if (i == 1)
			d->scrn.width = ft_atoi(res[i]);
		if (i == 2)
			d->scrn.height = ft_atoi(res[i]);
		i++;
	}
	if (i <= 1 || i >= 4)
		printf("is not resolution\n");		// resolution error
	is_valid_resol(d);
}

int		parse_info(t_gamedata *d, char *line, char **res)
{
	if (!*line)
		return (-1);	// empty value
	if (ft_strncmp("R", res[0],ft_strlen("R")) == 0)
		parse_resolution(d, res);
	else if (ft_strncmp("NO", res[0], ft_strlen("NO")) == 0)
		d->north_img = parse_texture(d, res[1]);
	else if (ft_strncmp("SO", res[0], ft_strlen("SO")) == 0)
		d->south_img = parse_texture(d, res[1]);
	else if (ft_strncmp("WE", res[0], ft_strlen("WE")) == 0)
		d->west_img = parse_texture(d, res[1]) ;
	else if (ft_strncmp("EA", res[0], ft_strlen("EA")) == 0)
		d->east_img = parse_texture(d, res[1]);
	else if (ft_strncmp("S", res[0], ft_strlen("S")) == 0)
		d->sprite_img = parse_texture(d, res[1]);
	else if (ft_strncmp("C", res[0], ft_strlen("C")) == 0)
		d->ceil_color = parse_color(res);
	else if (ft_strncmp("F", res[0], ft_strlen("F")) == 0)
		d->floor_color = parse_color(res);
	else
		return (2);		// able map parse
	return (1);			// unable map parse
}

int		parse_gamedata(t_gamedata *d, char *path)
{
	int			fd;
	int			eof;
	char		*line;
	char		**res;
	t_list		*map_lst;

	line = 0;
	map_lst = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("[%s] : WRONG CUB FILE PATH\n", path);	// GNL error 1
	while (1)
	{
		if ((eof = get_next_line(fd, &line)) < 0)
			printf("EOF ERROR!!!\n");		// GNL error 2
		res = ft_split(line, ' ');
		if (parse_info(d, line, res) == 2)
			parse_map(line, &map_lst);
		free(line);
		if (eof == 0)
			break ;
	}
	d->scrn.map_arr = lst2arr(d, map_lst);
	close(fd);
	return (0);	// no error
}
