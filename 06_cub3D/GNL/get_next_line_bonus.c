#include "get_next_line_bonus.h"

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

int			get_next_line(int fd, char **line)
{
	int			byte;
	char		*buf;
	char		*tmp_ptr;
	static char *store[OPEN_MAX];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX ||
			!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (_ERROR);
	if (!store[fd])
		store[fd] = ft_strndup("", 1);
	while (!(tmp_ptr = ft_strchr(store[fd], '\n')) &&
	(byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = 0;
		tmp_ptr = store[fd] != NULL ?
		ft_strjoin(store[fd], buf) : ft_strndup(buf, byte);
		if (store[fd])
			free(store[fd]);
		store[fd] = tmp_ptr;
	}
	free(buf);
	if (byte < 0)
		return (_ERROR);
	return (proc_remain(line, &store[fd], tmp_ptr));
}
