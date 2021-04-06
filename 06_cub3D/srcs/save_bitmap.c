#include "../includes/cub3d.h"

int		save_bitmap(int argc, char **argv, t_gamedata *d)
{
	int		fd;
	int		j;

	if (argc != 3 || ft_strncmp(argv[2], "--save", 6))
		return (0);
	fd = open("cub3D_screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND);
	if (fd < 0)
		return (0);


}