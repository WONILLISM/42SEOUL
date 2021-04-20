#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *s)
{
	int ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}
char	*make_line(char *line, char buf)
{
	char	*ret;
	int		i;

	if (!(ret = (char *)malloc(ft_strlen(line) + 2)))
		return (0);
	i = 0;
	while (line[i])
	{
		ret[i] = line[i];
		i++;
	}
	free(line);
	ret[i] = buf;
	ret[i + 1] = 0;
	return (ret);
}

int	get_next_line(char **line)
{
	char	buf;
	int		n;
	
	if (!(*line = malloc(1)))
		return (-1);
	*line[0] = 0;
	while ((n = read(0, &buf, 1)) > 0)
	{
		if (buf == '\n')
			return (1);
		*line = make_line(*line, buf);
		if (!*line)
			return (0);
	}
	if (n == -1)
		return (-1);
	return (0);
}
