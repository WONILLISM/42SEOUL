#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line)
{
	int			byte;
	char		*tmp_char;
	char		*tmp_store;
	char		buf[BUFFER_SIZE + 1];
	static char	*store;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (_ERROR);
	while (!(tmp_char = ft_strchr(store, '\n')) && (byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = 0;
		if (!store)
			tmp_store = ft_strndup(buf, byte);
		else
			tmp_store = ft_strjoin(store, buf);
		if (store)
			free(store);
		store = tmp_store;
	}
	if (byte < 0)
		return (_ERROR);
	return (0);
}

int		main(void)
{
	char	*line;
	int		ret;
	int		fd;

	fd = open("test", O_RDONLY);
	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("get_next_line : %s\n", line);
		printf("return value : %d\n\n", ret);
		free(line);
	}
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);
	return (0);
}
