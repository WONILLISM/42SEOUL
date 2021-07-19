#include "philoshopers.h"

void	*do_processphilo(void *philo)
{
	t_philos *p;

	p = philo;
	printf("philo[%d]'s status : %d\n", p->idx,p->status);
	printf("tid: %x\n", (unsigned int)p->pthrd);
	return (NULL);
}

int		init_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		data->n = ft_atoi(argv[1]);
		data->die = ft_atoi(argv[2]);
		data->eat = ft_atoi(argv[3]);
		data->sleep = ft_atoi(argv[4]);
		data->forks = (int *)malloc(sizeof(int) * data->n);
		if (data->forks == NULL)
			return (-1);
		while (i < data->n)
			data->forks[i++] = 0;
		if (argc == 6)
			data->must_eat =  ft_atoi(argv[5]);
		else
			data->must_eat = 0;
	}
	else
		return (-1);
	return (0);
}

int		init_philo(t_data *data, t_philos *philos)
{
	int	tid;
	int	i;

	i = 0;
	philos = (t_philos *)malloc(sizeof(t_philos) * data->n);
	if (philos == NULL)
		return (-1);
	while (i < data->n)
	{
		philos[i].data = data;
		philos[i].status = 0;
		philos[i].idx = i + 1;
		tid = pthread_create(&philos[i].pthrd, NULL, do_processphilo, (void *)(&philos[i]));
		if (tid < 0)
		{
			printf("pthread create func fail\n");
			exit(0);
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_data		data;
	t_philos	*philos;
	int			s;

	if (init_data(&data, argc, argv) == -1)
	{
		printf("wrong number of arguments.\n");
		exit(0);
	}
	if (init_philo(&data, philos))
	{
		printf("init philo error\n");
		exit(0);
	}
	for(int i = 0; i < data.n; i++)
		pthread_join(philos[i].pthrd, (void **)&s);
	return (0);
}
