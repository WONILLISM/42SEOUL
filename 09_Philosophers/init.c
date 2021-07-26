#include "philosophers.h"

int		init_thread(t_data *data)
{
	int	i;

	i = -1;
	data->cur_time = 0;
	data->die_flag = 0;
	data->mid = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (data->mid == NULL)
		return (-1);
	while (++i < data->num_of_philos)
		pthread_mutex_init(&data->mid[i], NULL);
	data->tid = (pthread_t *)
		malloc(sizeof(pthread_t) * data->num_of_philos);
	data->start_time = microtomilli();
	if (data->tid == NULL)
		return (-1);
	return (0);
}

int		init_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		data->num_of_philos = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->time_must_eat =  ft_atoi(argv[5]);
		else
			data->time_must_eat = 0;
	}
	else
		return (-1);
	return (0);
}

int		init_philo(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philos);
	if (*philo == NULL)
		return (-1);
	while (i < data->num_of_philos)
	{
		(*philo)[i].idx = i + 1;
		(*philo)[i].left_fork_idx = (data->num_of_philos + i - 1) % data->num_of_philos + 1;
		(*philo)[i].right_fork_idx = (data->num_of_philos + i + 1) % data->num_of_philos;
		(*philo)[i].status = 0;
		(*philo)[i].last_eat_time = microtomilli();
		(*philo)[i].data = data;
		i++;
	}
	return (0);
}
