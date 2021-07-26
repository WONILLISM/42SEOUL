#include "philosophers.h"

//void	print_status(t_philo *philo)
//{
//	pthread_mutex_lock(&philo->data->print);
//	printf("%ldms philo%d가 먹는 중이다.\n", microtomilli() - philo->data->start_time, philo->idx);
//	pthread_mutex_unlock(&philo->data->print);
//}
void	think_time(t_philo *philo)
{
	philo->status = 3;
	if (philo->data->die_flag == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms philo%d가 생각하는 중이다.\n", microtomilli() - philo->data->start_time, philo->idx);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void	sleep_time(t_philo *philo)
{
	philo->status = 2;
	if (philo->data->die_flag == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms philo%d가 자는 중이다.\n", microtomilli() - philo->data->start_time, philo->idx);
		pthread_mutex_unlock(&philo->data->print);
	}
	ft_sleep(philo->data->time_to_sleep, microtomilli());
}

void	meal_time(t_philo *philo)
{
	philo->status = 1;
	if (philo->data->die_flag == 0)
	{
		//print_status(philo);
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms philo%d가 먹는 중이다.\n", microtomilli() - philo->data->start_time, philo->idx);
		pthread_mutex_unlock(&philo->data->print);
	}
	ft_sleep(philo->data->time_to_eat, microtomilli());
	philo->last_eat_time = microtomilli();
	pthread_mutex_unlock(&philo->data->mid[philo->left_fork_idx - 1]);
	pthread_mutex_unlock(&philo->data->mid[philo->right_fork_idx - 1]);
}

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mid[philo->left_fork_idx - 1]);
	//printf("%ldms philo%d가 포크를 잡았다.\n", microtomilli() - philo->data->start_time, philo->idx);
	pthread_mutex_lock(&philo->data->mid[philo->right_fork_idx - 1]);
	if (philo->data->die_flag == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms philo%d가 포크를 잡았다.\n", microtomilli() - philo->data->start_time, philo->idx);
		pthread_mutex_unlock(&philo->data->print);
	}
}
