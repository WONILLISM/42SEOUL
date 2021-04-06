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
	write(fd, "BM", 2);
	write(fd, d->scrn.width * d->scrn.height * 4, 4);
	write(fd, 0, 4);
	write(fd, 54, 4);
	write(fd, d->scrn.width, 4);
	write(fd, d->scrn.height, 4);
	write(fd, 40, 4);
	write(fd, 1, 2);
	write(fd, 32, 2);
	j = -1;
	while (++j < 6)
		write(fd, 0, 4);
	j = d->scrn.height;
	while (--j >= 0)
		write(fd, d->scrn.view.addr + d->scrn.width * j, d->scrn.width);
	close(fd);
	exit(0);
}