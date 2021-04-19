#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int ft_strlen(char *str)
{
	int cnt = 0;

	while (str[cnt])
		cnt++;
	return (cnt);
}
char *ft_charappend(char *line, char buff)
{
	int idx = 0;
	char *rst;
	if (!(rst = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1))))
		return (NULL);
	while (line[idx])
	{
		rst[idx] = line[idx];
		++idx;
	}
	rst[idx] = buff;
	++idx;
	rst[idx] = 0;
	free(line);
	return (rst);
}
int get_next_line(char **line)
{
	int rb;
	char buff;
	if (!line)
		return (0);
	*line = (char *)malloc(sizeof(char));
	line = 0;
	while ((rb = read(0, &buff, 1) > 0))
	{
		printf("%c\n",buff);
		if (buff == '\n')
			return (1);
		*line = ft_charappend(*line, buff);
		if (!*line)
			return (0);
	}
	if (rb == -1)
		return (-1);
 return (0);
}
#include <fcntl.h>
int	main(void)
{
	int fd;
	char *line;
	fd = 0;
	while (get_next_line(&line) > 0)
	{
		printf("here?\n");
		printf("%s\n",line);
	}
}
