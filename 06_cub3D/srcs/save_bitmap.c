#include "../includes/cub3d.h"

size_t	put_bitmap_data(int fd, size_t data, size_t size)
{
	size_t	ret;

	ret = write(fd, &data, size);
	return (ret);
}

void		save_bitmap(t_gamedata *d)
{
	int		fd;
	int		j;

	if (d->argc != 3 || ft_strncmp(d->argv[2], "--save", 6))
		printf("Error\n");
	fd = open("cub3D_screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0664);
	if (fd < 0)
		printf("Error\n");
	write(fd, "BM", 2);
	put_bitmap_data(fd, d->scrn.width * d->scrn.height * 4 + 54, 4); // header size
	put_bitmap_data(fd, 0, 4); // header reserved1
	put_bitmap_data(fd, 54, 4); //header off bits
	put_bitmap_data(fd, 40, 4); // info size
	put_bitmap_data(fd, d->scrn.width, 4); // info width
	put_bitmap_data(fd, d->scrn.height, 4); // info heigth
	put_bitmap_data(fd, 1, 2); // info planes
	put_bitmap_data(fd, 32, 2); // info bit count
	j = -1;
	while (++j < 6)
		put_bitmap_data(fd, 0, 4); // info x pels per meter
	j = d->scrn.height;
	while (--j >= 0)
		write(fd, d->scrn.view.addr + d->scrn.width * j, d->scrn.width * 4);
	close(fd);
	exit(0);
}
