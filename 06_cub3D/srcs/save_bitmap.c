#include "../includes/cub3d.h"

int		chk_save_cmd(char **argv, t_gamedata *d)
{
	int		i;
	char	*s1;
	char	*s2;

	s1 = "--save";
	s2 = argv[2];
	while (1)
	{
		if (*s1 != *s2)
			error_message("save param", d);
		s1++;
		s2++;
	}
	return (1);
}

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

	fd = open("cub3D_screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0664);
	if (fd < 0)
		printf("Error\n");
	write(fd, "BM", 2);
	put_bitmap_data(fd, d->scrn.width * d->scrn.height * 4 + 54, 4); // header size
	put_bitmap_data(fd, 0, 4); // header reserved
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
