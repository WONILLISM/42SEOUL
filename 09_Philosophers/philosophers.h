#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_data
{
	long			start_time;
	long			cur_time;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int				*forks;
	pthread_t		*tid;
	pthread_mutex_t	*mid;
}				t_data;

typedef struct s_philo
{
	t_data		*data;
	int			status;
	int			idx;
	long		last_eat_time;
}				t_philo;

int	ft_isdigit(int c);
int	ft_atoi(const char *str);

int		init_thread(t_data *data);
int		init_data(t_data *data, int argc, char **argv);
int		init_philo(t_data *data, t_philo **philo);

long	microtomilli();
void	ft_sleep(long t, long cur);
#endif
