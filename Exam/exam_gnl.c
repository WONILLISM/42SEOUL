#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
​
int		ft_strlen(char *str)
{
	int	idx;
​
	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}
​
char	*ft_make_line(char *line, char buff)
{
	char	*result;
	int		idx;
​
	idx = 0;
	if (!(result = (char *)malloc(ft_strlen(line) + 2));
		return (NULL);
	while (line[idx])
	{
		result[idx] = line[idx];
		idx++;
	}
	free(line);
	result[idx] = buff;
	result[idx + 1] = '\0';
	return (result);
}
​
int		get_next_line(char **line)
{
	int		read_nbr;
	char	buff;
​
	if (!(*line = malloc(1)))
		return (-1);
	*line[0] = '\0';
	while ((read_nbr = read(0, &buff, 1)) > 0)
	{
		if (buff == '\n')
			return (1);
		*line = ft_make_line(*line, buff);
		if (!*line)
			return (0);
	}
	if (read_nbr == -1)
		return (-1);
	return (0);
}
​
int		main(void)
{
	char	*line;
	int		a;
​
	while ((a = get_next_line(&line)) > -1)
	{
		printf("Get_next_line Result : %d\n", a);
		printf("in the line : %s\n\n", line);
		if (a == 0)
			break ;
	}
	return (0);
}