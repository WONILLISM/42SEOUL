#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void    ft_sort_params(int argc, char **argv)
{
    char    *tmp;
    int     i;
    int     j;

    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_strcmp(argv[i], argv[j])>=1)
            {
                tmp = argv[i];
                argv[i] = argv[j];
                argv[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

int		main(int argc, char **argv)
{
	int	i;

	i = 0;
    ft_sort_params(argc, argv);
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
	}
}
