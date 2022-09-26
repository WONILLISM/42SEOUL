#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char **argv)
{
	int num;
	int i;

	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num == 1)
			printf("1");
		i = 2;
		while (i <= num)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				num /= i;
				if (num == 1)
					break;
				printf("*");
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}