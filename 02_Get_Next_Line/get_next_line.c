#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static int		ret_line(char **line, char *store, char *tmp_char)
{
	char	*tmp;
	size_t	len;

	if (tmp_char)
	{
		*line = ft_strndup(store, tmp_char - store);
		len = ft_strlen(tmp_char + 1);
		tmp = ft_strndup(tmp_char + 1, len);
		free(store);
		store = tmp;
	}
	if (store)
	{
		*line = store;
		store = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (_EOF);
}

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
	return (ret_line(line, store, tmp_char));
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
