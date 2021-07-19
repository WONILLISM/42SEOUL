#ifndef PHILOSHOPERS_H
# define PHILOSHOPERS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_data
{
	int		n;
	int		die;
	int		eat;
	int		sleep;
	int		must_eat;
	int		*forks;
}				t_data;

typedef struct s_philos
{
	pthread_t	pthrd;
	t_data		*data;
	int			status;
	int			idx;
}				t_philos;

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
#endif
