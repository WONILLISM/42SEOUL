#ifndef PHILOSHOPERS_H
# define PHILOSHOPERS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_data
{
	long			start_time;
	long			cur_time;
	int				nimofphilo;
	int				timetodie;
	int				timetoeat;
	int				timetosleep;
	int				timemust_eat;
	int				*forks;
	pthread_t		*tid;
	pthread_mutex_t	*mid;
}				t_data;

typedef struct s_philo
{
	t_data		*data;
	int			status;
	int			idx;
}				t_philo;

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
#endif
