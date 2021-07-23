#include "philoshopers.h"

long	microtomilli()
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	return (tmp.tv_sec * 1000L + tmp.tv_usec / 1000);
}

void	ft_sleep(long t, long cur)
{
	long	res;
	//long	tmp;

	res = cur + t;
	while (microtomilli() < res)
	{
		//tmp = (long)((res - microtomilli())/2);
		//usleep(tmp * 1000);
		usleep((long)((res - microtomilli())/2) * 1000);
	}
}

void	*do_processphilo(void *philo)
{
	struct timeval	t;
	t_philos 		*p;
	long			cur;
	int 			lf;
	int 			rf;

	p = philo;
	if (p->idx == 1)
	{
		lf = p->data->n;
		rf = 2;
	}
	else if (p->idx == p->data->n)
	{
		lf = p->data->n - 1;
		rf = 1;
	}
	else
	{
		lf = p->idx - 1;
		rf = p->idx + 1;
	}
	if (p->data->forks[lf - 1] == 0 && p->data->forks[rf - 1] == 0)
	{
		p->data->forks[lf - 1] = 1;
		p->data->forks[rf - 1] = 1;
		cur = microtomilli();
		printf("philo%d가 %ldms에 식사를 시작했습니다.\n", p->idx, cur - (p->data->start.tv_sec * 1000 + p->data->start.tv_usec/1000));
		ft_sleep(p->data->eat, cur);
		printf("philo%d가 %ldms에 식사를 마쳤습니다.\n", p->idx, microtomilli() - (p->data->start.tv_sec * 1000 + p->data->start.tv_usec/1000));
		p->data->forks[lf - 1] = 0;
		p->data->forks[rf - 1] = 0;
	}
	return (NULL);
}

int		init_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		gettimeofday(&data->start, NULL);
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

int		init_philo(t_data *data, t_philos **philos)
{
	int	tid;
	int	i;

	i = 0;
	*philos = (t_philos *)malloc(sizeof(t_philos) * data->n);
	if (*philos == NULL)
		return (-1);
	while (i < data->n)
	{
		(*philos)[i].data = data;
		(*philos)[i].status = 0;
		(*philos)[i].idx = i + 1;
		tid = pthread_create(&(*philos)[i].pthrd, NULL, do_processphilo, (void *)(&(*philos)[i]));
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

	if (init_data(&data, argc, argv) == -1)
	{
		printf("wrong number of arguments.\n");
		exit(0);
	}
	if (init_philo(&data, &philos))
	{
		printf("init philo error\n");
		exit(0);
	}
	for(int i = 0; i < data.n; i++)
		pthread_join(philos[i].pthrd, 0);
	return (0);
}
