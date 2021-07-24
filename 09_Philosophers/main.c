#include "philosophers.h"

void	*philo_process(void *param)
{
	t_data	*data;
	t_philo	*philo;

	philo = param;
	data = philo->data;
	//while (1)
	//{
		pick_fork(philo);
		//meal_time(philo);
		//sleep_time(philo);
		//think_time(philo);
	//}
	return (NULL);
}

int		philoshopers(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_create(
			&data->tid[i], NULL, philo_process, &philo[i]);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;

	if (init_data(&data, argc, argv) == -1)
	{
		printf("wrong number of arguments.\n");
		exit(0);
	}
	if (init_philo(&data, &philo))
	{
		printf("init philo error\n");
		exit(0);
	}
	if (init_thread(&data))
	{
		printf("init thread error\n");
		exit(0);
	}
	data.start_time = microtomilli();
	philoshopers(&data, philo);
	for (int i = 0; i < data.num_of_philos; i++)
		pthread_join(data.tid[i], NULL);
	return (0);
}
