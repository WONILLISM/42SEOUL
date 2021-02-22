#include "cub3d.h"

int		main(void)
{
	t_data	data;
	int		ret;
	int		fd;
	char	*line;

	line = 0;
	fd = open("./cub3d.cub",O_RDONLY);

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
	}

	// cub3d(&data);	
	return (0);
}