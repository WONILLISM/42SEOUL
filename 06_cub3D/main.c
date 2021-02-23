#include "includes/cub3d.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		set_resolution(char *l)
{
	char	*w;
	char	*h;
	int		idx;

	idx = 0;
	while (*l != ' ' && *l)
		l++;
	l++;
	printf("%s", l);
	while (1)
	{
		// printf("%c", *l);
		if (idx++ == 0)
			w = l;
		if (idx++ == 1)
			h = l;
		while (*l != ' ' && *l)
			l++;
		if (!*l)
			break;
		l++;
	}
	printf("%s %s\n", w, h);
	return (0);
}

int		main(void)
{
	t_data		data;
	int			ret;
	int			fd;
	char		*line;

	line = 0;
	fd = open("./cub3d.cub",O_RDONLY);

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'R')
			set_resolution(line);
		// printf("%c\n", line[0]);
	}
	cub3d(&data);
	return (0);
}
