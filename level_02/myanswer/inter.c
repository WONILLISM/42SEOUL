#include <unistd.h>
#include <stdio.h>

int		g_chk_c[128] = {0, };
void	ft_inter(char *str1, char *str2)
{
	
	int i;
	int j;
	
	i = 0;
	j = 0;
	printf("str1  str2  chk\n");
	while (str1[i])
	{
		g_chk_c[str1[i]]++;
		printf("%c ",str1[i]);
		while(str2[j])
		{
			
			if (g_chk_c[str2[j]] == 1 && str1[i] == str2[j])
			{
				g_chk_c[str2[j]]++;
				write(1, &str1[i], 1);
				j++;
				break;
			}
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}