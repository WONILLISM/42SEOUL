#include "get_next_line.h"

static int	proc_remain(char **line, char **store, char *tmp_ptr)
{
	char *tmp;

	if (tmp_ptr)
	{
		*line = ft_strndup(*store, tmp_ptr - *store);
		tmp = ft_strndup(tmp_ptr + 1, ft_strlen(tmp_ptr + 1));
		free(*store);
		*store = tmp;
		return (_SUC_READ);
	}
	if (*store)
	{
		*line = *store;
		*store = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (_EOF);
}

int		get_next_line(int fd, char **line)
{
	int			byte;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp_ptr;
	static char	*store[OPEN_MAX];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (_ERROR);
	if (!store[fd])
		store[fd] = ft_strndup("", 1);
	while (!(tmp_ptr = ft_strchr(store[fd],'\n'))
	&& (byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = 0;
		if (store[fd])
			tmp_ptr = ft_strjoin(store[fd], buf);
		else
			tmp_ptr = ft_strndup(buf, byte);
		if (store[fd])
			free(store[fd]);
		store[fd] = tmp_ptr;
	}

	if (byte < 0)
		return (_ERROR);
	return (proc_remain(line, &store[fd], tmp_ptr));
}

// int		main(void)
// {
// 	char	*line;
// 	int		ret;
// 	int		fd;

// 	fd = open("test", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("get_next_line : %s\n", line);
// 		printf("return value : %d\n\n", ret);
// 		free(line);
// 	}
// 	// ret = get_next_line(fd, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n", ret);
// 	free(line);
// 	return (0);
// }
