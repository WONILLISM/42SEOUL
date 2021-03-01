// #include "includes/cub3d.h"

// // ft_atoi
// // ft_split
// // ft_strncpm
// // ft_isdigit
// // ft_atoi


// int		parse_resolution(char **line, t_data *d)
// {
// 	int		i;
// 	int		j;

// 	i = 1;
// 	while (line[i])
// 	{
// 		j = 0;
// 		while (line[i][j])
// 		{
// 			if (!ft_isdigit(line[i][j]))
// 				return (0);
// 			j++;
// 		}
// 		if (i == 1)
// 			d->a.width = ft_atoi(line[i]);
// 		if (i == 2)
// 			d->a.height = ft_atoi(line[i]);
// 		i++;
// 	}
// 	if (i <= 1 || i >= 4)
// 		return (0);
// 	return (1);
// }

// int		parse_map(char **line, t_data *d)
// {
// 	t_list *lst;

// 	lst = ft_lstnew()
// }

// int		parse_check(char *s, char **line, t_data *d)
// {
// 	if (ft_strncmp("R", s,ft_strlen("R")) == 0)
// 	{
// 		if (!parse_resolution(line, d))
// 			return (0);
// 	}
// 	else if (ft_strncmp("NO",s, ft_strlen("NO")) == 0)
// 	{
// 		if (!(d->north_img.path = line[1]))
// 			return (0);
// 	}
// 	else if (ft_strncmp("SO",s, ft_strlen("SO")) == 0)
// 	{
// 		if (!(d->south_img.path = line[1]))
// 			return (0);
// 	}
// 	else if (ft_strncmp("WE",s, ft_strlen("WE")) == 0)
// 	{
// 		if (!(d->west_img.path = line[1]))
// 			return (0);
// 	}
// 	else if (ft_strncmp("EA",s, ft_strlen("EA")) == 0)
// 	{
// 		if (!(d->east_img.path = line[1]))
// 			return (0);
// 	}
// 	else if (*s == ' ' || *s == '1')
// 	{
// 		parse_map(line, d);
// 	}
// 	printf("%s\n", d->south_img.path);
// 	// else if (ft_strncmp(s, "S", ft_strlen(s)) == 0)
// 	// else if (ft_strncmp(s, "F", ft_strlen(s)) == 0)
// 	// else if (ft_strncmp(s, "O", ft_strlen(s)) == 0)
// 	// else
// 	return (0);
// }
// int		main(void)
// {
// 	t_data		data;
// 	int			ret;
// 	int			fd;
// 	char		*line;
// 	char		**res;

// 	line = 0;
// 	if ((fd = open("./cub3d.cub",O_RDONLY) < 0))
// 		printf("error\n");
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		res = ft_split(line,' ');
// 		if (res[0])
// 			parse_check(res[0], res, &data);
// 	}
// 	cub3d(&data);
// 	return (0);
// }
#include "includes/cub3d.h"

// ft_atoi
// ft_split
// ft_strncpm
// ft_isdigit
// ft_atoi

void	free_split(char **res)
{
	char	**tmp;

	if (!res)
		return ;
	tmp = res;
	while (*tmp)
		free(*tmp++);
	free(res);
}

int		parse_resolution(char **res, t_data *d)
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
				return (0);
			j++;
		}
		if (i == 1)
			d->a.width = ft_atoi(res[i]);
		if (i == 2)
			d->a.height = ft_atoi(res[i]);
		i++;
	}
	if (i <= 1 || i >= 4)
		return (0);
	return (1);
}

// int		parse_map(char *line, t_list **map)
// {
// 	char	*tmp;

// 	tmp = 
// }

int		parse_texture(char **res, t_data *game_d)
{
	if (ft_strncmp("NO", res[0], ft_strlen("NO")) == 0)
	{
		if (!(game_d->north_img.path = res[1]))
			return (0);
	}
	else if (ft_strncmp("SO", res[0], ft_strlen("SO")) == 0)
	{
		if (!(game_d->south_img.path = res[1]))
			return (0);
	}
	else if (ft_strncmp("WE", res[0], ft_strlen("WE")) == 0)
	{
		if (!(game_d->west_img.path = res[1]))
			return (0);
	}
	else if (ft_strncmp("EA", res[0], ft_strlen("EA")) == 0)
	{
		if (!(game_d->east_img.path = res[1]))
			return (0);
	}
	// else if (ft_strncmp(s, "S", ft_strlen(s)) == 0)
	// else if (ft_strncmp(s, "C", ft_strlen(s)) == 0)
	// else if (ft_strncmp(s, "F", ft_strlen(s)) == 0)

	return (0);
}

int		parse_check(char **res, t_data *game_d)
{
	if (ft_strncmp("R", res[0],ft_strlen("R")) == 0)
	{
		if (!parse_resolution(res, game_d))
			return (0);
	}
	else 
	{
		if (!parse_texture(res, game_d))
			return (0);
	}
	return (0);
}

// void	put_game_data(t_data *game_d, char **res, int i, char **spec)
// {
// 	printf("parsing : %s ...\n", spec[i]);
// 	if (i == )
// }

int		parse_info(t_data *game_d, char *line)
{
	char	**res;
	char	**specifier;
	int		i;

	if (!(*line))
		return (-1);
	specifier = ft_split(TEXTURE_SPEC, ' ');
	res = ft_split(line, ' ');
	i = 0;
	while (specifier[i])
	{
		if (ft_srtcmp(res[0], specifier[i], 10) == 0)
		{
			parse_check(res, game_d);
			free_split(res);
			return (0);
		}
		i++;
	}
	free_split(res);
	return (1);
}

int		init_data(char *path, t_data *game_d)
{
	int			fd;
	int			eof;
	char		*line;
	char		**map_arr;
	t_list		*map_lst;

	line = 0;
	if ((fd = open(path,O_RDONLY) < 0))
		printf("[%s] : WRONG CUB FILE PATH\n", path);
	while (1)
	{
		if  ((eof = get_next_line(fd, &line)) < 0)
			printf("EOF ERROR!!!");
		if (parse_info(game_d,line) == 1)
			parse_map(line, &map_lst);
		free(line);
		if (eof == 0)
			break ;
	}
	close(fd);
	// while ((ret = get_next_line(fd, &line)) > 0)
	// {
	// 	res = ft_split(line,' ');
	// 	if (res[0])
	// 		parse_check(res[0], res, &data);
	// }
}

int		main(void)
{
	t_data		data;
	
	cub3d(&data);
	return (0);
}
