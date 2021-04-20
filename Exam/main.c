#include <stdio.h>

int main(void)
{
	int		r;
	char	*line;

	while ((r = get_next_line(&line) > -1))
	{
		printf("gnl res : %d\n", r);
		printf("line : %s\n", line);
		if (r == 0)
			break;
	}
	return (0);
}
