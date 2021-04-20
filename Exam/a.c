#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

char	*ft_make_line(char *line, char buf)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = (char *)malloc(ft_strlen(line) + 2)))
		return (NULL);
	while (line[i])
	{
		res[i] = line[i];
		i++;
	}
	free(line);
	res[i] = buf;
	res[i + 1] = 0;
	return (res);
}

int get_next_line(char **line)
{
	int		read_nbr;
	char	buf;

	if (!(*line = malloc(1)))
		return (-1);
	*line[0] = 0;
	while ((read_nbr = read(0, &buf, 1)) > 0)
	{
		if (buf == '\n')
			return (1);
		*line = ft_make_line(*line, buf);
		if (*line)
			return (0);
	}
	if (read_nbr == -1)
		return (-1);
	return (0);
}

int main(void)
{
	char    *line;
	int     r;

	while ((r = get_next_line(&line)) > -1)
	{
		printf("GNL Res : %d\n",r);
		printf("line : %s\n", line);
		if (r == 0)
			break;
	}
	return (0);
}
