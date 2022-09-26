/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:40:33 by wopark            #+#    #+#             */
/*   Updated: 2021/04/13 14:40:54 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		chk_save_cmd(char **argv, t_gamedata *d)
{
	int		i;
	char	*s1;
	char	*s2;

	s1 = "--save";
	s2 = argv[2];
	if (ft_strlen(s1) != ft_strlen(s2))
		error_message("save param", d);
	while (*s1)
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

void	save_bitmap(t_gamedata *d)
{
	int		fd;
	int		j;

	fd = open("cub3D_screenshot.bmp", O_WRONLY | O_CREAT
	| O_TRUNC | O_APPEND, 0664);
	if (fd < 0)
		error_message("fd", d);
	write(fd, "BM", 2);
	put_bitmap_data(fd, d->scrn.width * d->scrn.height * 4 + 54, 4);
	put_bitmap_data(fd, 0, 4);
	put_bitmap_data(fd, 54, 4);
	put_bitmap_data(fd, 40, 4);
	put_bitmap_data(fd, d->scrn.width, 4);
	put_bitmap_data(fd, d->scrn.height, 4);
	put_bitmap_data(fd, 1, 2);
	put_bitmap_data(fd, 32, 2);
	j = -1;
	while (++j < 6)
		put_bitmap_data(fd, 0, 4);
	j = d->scrn.height;
	while (--j >= 0)
		write(fd, d->scrn.view.addr + d->scrn.width * j, d->scrn.width * 4);
	close(fd);
	exit(0);
}
