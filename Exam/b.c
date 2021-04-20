#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int		ft_strlen(char *s)
{
	int	ret;

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
	for (i = 0; line[i]; i++)
		ret[i] = line[i];
	free(line);
	ret[i] = buf;
	ret[i + 1] = 0;
	return (ret);
}

int	get_next_line(char **line)
{
	int		n;
	char	buf;

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

int	main(void)
{
	char	*line;
	int		r;

	while ((r = get_next_line(&line)) > -1)
	{
		printf("GNL res : %d\n", r);
		printf("line : %s\n", line);
		if (r == 0)
			break;
	}
	return (0);
}
