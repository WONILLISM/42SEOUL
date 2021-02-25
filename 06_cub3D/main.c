#include "includes/cub3d.h"

// ft_atoi
// ft_split
// ft_strncpm
// ft_isdigit
// ft_atoi


int		parse_resolution(char **line, t_data *d)
{
	int		i;
	int		j;

	i = 1;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (!ft_isdigit(line[i][j]))
				return (0);
			j++;
		}
		if (i == 1)
			d->a.width = ft_atoi(line[i]);
		if (i == 2)
			d->a.height = ft_atoi(line[i]);
		i++;
	}
	if (i <= 1 || i >= 4)
		return (0);
	return (1);
}

int		parse_map(char **line, t_data *d)
{
	t_list *lst;

	lst = ft_lstnew()
}

int		parse_check(char *s, char **line, t_data *d)
{
	if (ft_strncmp("R", s,ft_strlen("R")) == 0)
	{
		if (!parse_resolution(line, d))
			return (0);
	}
	else if (ft_strncmp("NO",s, ft_strlen("NO")) == 0)
	{
		if (!(d->north_img.path = line[1]))
			return (0);
	}
	else if (ft_strncmp("SO",s, ft_strlen("SO")) == 0)
	{
		if (!(d->south_img.path = line[1]))
			return (0);
	}
	else if (ft_strncmp("WE",s, ft_strlen("WE")) == 0)
	{
		if (!(d->west_img.path = line[1]))
			return (0);
	}
	else if (ft_strncmp("EA",s, ft_strlen("EA")) == 0)
	{
		if (!(d->east_img.path = line[1]))
			return (0);
	}
	else if (*s == ' ' || *s == '1')
	{
		parse_map(line, d);
	}
	printf("%s\n", d->south_img.path);
	// else if (ft_strncmp(s, "S", ft_strlen(s)) == 0)
	// else if (ft_strncmp(s, "F", ft_strlen(s)) == 0)
	// else if (ft_strncmp(s, "O", ft_strlen(s)) == 0)
	// else
	return (0);
}
int		main(void)
{
	t_data		data;
	int			ret;
	int			fd;
	char		*line;
	char		**res;

	line = 0;
	if ((fd = open("./cub3d.cub",O_RDONLY) < 0))
		printf("error\n");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		res = ft_split(line,' ');
		if (res[0])
			parse_check(res[0], res, &data);
	}
	cub3d(&data);
	return (0);
}
