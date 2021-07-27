#include "philosophers.h"

void	think_time(t_philo *philo)
{
	philo->status = 3;
	if (philo->data->die_flag == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms philo%d is thinking.\n", \
			microtomilli() - philo->data->start_time, philo->idx);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void	sleep_time(t_philo *philo)
{
	philo->status = 2;
	if (philo->data->die_flag == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms philo%d is sleepings.\n", \
			microtomilli() - philo->data->start_time, philo->idx);
		pthread_mutex_unlock(&philo->data->print);
	}
	ft_sleep(philo->data->time_to_sleep, microtomilli());
}

void	meal_time(t_philo *philo)
{
	philo->status = 1;
	if (philo->data->die_flag == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms philo%d is eatings.\n", \
			microtomilli() - philo->data->start_time, philo->idx);
		pthread_mutex_unlock(&philo->data->print);
	}
	ft_sleep(philo->data->time_to_eat, microtomilli());
	philo->last_eat_time = microtomilli();
	philo->eat_cnt += 1;
	if (philo->eat_cnt == philo->data->time_must_eat)
		philo->data->must_flag += 1;
	pthread_mutex_unlock(&philo->data->mid[philo->left_fork_idx - 1]);
	pthread_mutex_unlock(&philo->data->mid[philo->right_fork_idx - 1]);
}

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mid[philo->left_fork_idx - 1]);
	pthread_mutex_lock(&philo->data->mid[philo->right_fork_idx - 1]);
	if (philo->data->die_flag == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms philo%d has taken fork.\n", \
			microtomilli() - philo->data->start_time, philo->idx);
		pthread_mutex_unlock(&philo->data->print);
	}
}
