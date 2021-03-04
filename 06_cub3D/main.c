#include "includes/cub3d.h"

int		is_valid_map(t_data *d)
{
	int i;

	i = 0;
	while (i < d->a.col_size)
	{
		if (d->a.map[0][i] != '1' || d->a.map[d->a.col_size - 1][i] != '1')
			return (-1);
		if (d->a.map[i][0] != '1' || d->a.map[i][d->a.row_size - 1] != '1')
			return (-1);
		i++;
	}
	return (1);
}

void	init_player(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->a.row_size)
	{
		j = 0;
		while (j < d->a.col_size)
		{
			if (d->a.map[i][j] == 'N')
			{
				d->a.p.pos.x = j + 0.5;
				d->a.p.pos.y = i + 0.5;
				d->a.p.dir.x = 0;
				d->a.p.dir.y = -1;
				d->a.s.plane.x = 0.66;
				d->a.s.plane.y = 0;
			}
			else if (d->a.map[i][j] == 'E')
			{
				d->a.p.pos.x = j + 0.5;
				d->a.p.pos.y = i + 0.5;
				d->a.p.dir.x = 1.0;
				d->a.p.dir.y = 0;
				d->a.s.plane.x = 0;
				d->a.s.plane.y = 0.66;
			}
			else if (d->a.map[i][j] == 'W')
			{
				d->a.p.pos.x = j + 0.5;
				d->a.p.pos.y = i + 0.5;
				d->a.p.dir.x = -1.0;
				d->a.p.dir.y = 0;
				d->a.s.plane.x = 0;
				d->a.s.plane.y = -0.66;
			}
			else if (d->a.map[i][j] == 'S')
			{
				d->a.p.pos.x = j + 0.5;
				d->a.p.pos.y = i + 0.5;
				d->a.p.dir.x = 0;
				d->a.p.dir.y = 1;
				d->a.s.plane.x = -0.66;
				d->a.s.plane.y = 0;
			}
			j++;
		}
		i++;
	}
	// d->a.p.pos.x = 8.1f;
	// d->a.p.pos.y = 8.1f;
	// d->a.p.dir.x = -1.0f;
	// d->a.p.dir.y = 0.0f;
	d->a.p.move_speed = 0.05f;
	d->a.p.rot_speed = 0.02f;
}

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
int		get_col_size(t_list *lst)
{
	int		ret;
	int		size;

	ret = 0;
	while (lst)
	{
		size = ft_strlen(lst->content);
		if (ret < size)
			ret = size;
		lst = lst->next;
	}
	return (ret);
}
char	**lst2arr(t_data *game_d, t_list *lst)
{
	char	**ret;
	int		i;

	game_d->a.col_size = get_col_size(lst);
	game_d->a.row_size = ft_lstsize(lst);
	if (!(ret = (char **)malloc(sizeof(char *) * ft_lstsize(lst) + 1)))
		return (0);
	i = 0;
	while (lst)
	{
		if (!(ret[i] = (char *)malloc(sizeof(char) * game_d->a.col_size + 1)))
			return (0);
		ft_strlcpy(ret[i], lst->content, game_d->a.col_size + 1);
		i++;
		lst = lst->next;
	}
	ret[i] = 0;
	return (ret);
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

void	parse_map(char *line, t_list **map)
{
	char	*tmp;

	tmp = line;
	while (*line)
	{
		if (ft_strchr("012NEWS ", *tmp) == 0)
		{
			printf("Wrong map element\n");
			return ;
		}
		if (*line == ' ')
			*line = '1';
		line++;
	}
	ft_lstadd_back(map, ft_lstnew(ft_strdup(tmp)));
}

int		parse_color(char **res)
{
	char	**tmp;
	int		color;
	int		i;

	tmp = ft_split(res[1], ',');
	color = 0;
	i = -1;
	while (++i < 3)
		color += ft_atoi(tmp[i]) << ((2 - i) * 8);
	free_split(tmp);
	return (color);
}

void	set_texture(t_data *d, char *s, int *ret)
{
	t_img	img;
	int		i;
	int		j;

	img.ptr = mlx_xpm_file_to_image(d->a.m.mlx, s, &img.w, &img.h);
	img.addr = (unsigned int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	ret = (int *)malloc(sizeof(int) * img.w * img.h);
	i = -1;
	while (++i < img.h)
	{
		j = -1;
		while (++j < img.w)
			ret[img.w * i + j] = img.addr[img.w * i + j];
	}
	printf("%d\n", ret[0]);
	mlx_destroy_image(d->a.m.mlx, img.ptr);
}

int		parse_info(t_data *game_d, char *line)
{
	char	**res;

	if (!(*line))
		return (-1);
	res = ft_split(line, ' ');
	if (ft_strncmp("R", res[0],ft_strlen("R")) == 0)
		parse_resolution(res, game_d);
	else if (ft_strncmp("NO", res[0], ft_strlen("NO")) == 0)
		set_texture(game_d, res[1], game_d->north);
	else if (ft_strncmp("SO", res[0], ft_strlen("SO")) == 0)
		set_texture(game_d, res[1], game_d->south);
	else if (ft_strncmp("WE", res[0], ft_strlen("WE")) == 0)
		set_texture(game_d, res[1], game_d->west);
	else if (ft_strncmp("EA", res[0], ft_strlen("EA")) == 0)
		set_texture(game_d, res[1], game_d->east);
	else if (ft_strncmp("S", res[0], ft_strlen("S")) == 0)
		set_texture(game_d, res[1], game_d->sprite);
	else if (ft_strncmp("C", res[0], ft_strlen("C")) == 0)
		game_d->ceil_color = parse_color(res);
	else if (ft_strncmp("F", res[0], ft_strlen("F")) == 0)
		game_d->floor_color = parse_color(res);
	else
	{
		free_split(res);
		return (2);
	}
	free_split(res);
	return (0);
}

int		parse_data(char *path, t_data *game_d)
{
	int			fd;
	int			eof;
	int			info_res;
	char		*line;
	char		**map_arr;
	t_list		*map_lst;

	line = 0;
	map_lst = 0;
	if ((fd = open(path,O_RDONLY)) < 0)
		printf("[%s] : WRONG CUB FILE PATH\n", path);
	while (1)
	{
		if ((eof = get_next_line(fd, &line)) < 0)
			printf("EOF ERROR!!!\n");
		if (parse_info(game_d,line) == 2)
			parse_map(line, &map_lst);
		free(line);
		if (eof == 0)
			break ;
	}
	game_d->a.map = lst2arr(game_d, map_lst);
	close(fd);
	return (0);
}

int		main(void)
{
	t_data		data;

	data.a.m.mlx = mlx_init();
	data.a.m.win = mlx_new_window(data.a.m.mlx, data.a.width, data.a.height, "cub3d");
	parse_data("./cub3d.cub", &data);
	// printf("%d\n", data.north[0]);
	init_player(&data);
	cub3d(&data);
	return (0);
}
