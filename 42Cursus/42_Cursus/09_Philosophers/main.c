/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:42:23 by wopark            #+#    #+#             */
/*   Updated: 2021/07/27 18:42:25 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*die_check(void *param)
{
	t_philo	*philo;

	philo = param;
	while (1)
	{
		if (microtomilli() - philo->last_eat_time >= philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->data->print);
			printf("%ldms philo%d died.\n",
				microtomilli() - philo->data->start_time, philo->idx);
			philo->data->die_flag = 1;
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

void	*philo_process(void *param)
{
	t_philo		*philo;
	pthread_t	pid;

	philo = param;
	pthread_create(&pid, NULL, die_check, philo);
	if (philo->idx % 2 == 1)
		ft_sleep(philo->data->time_to_eat, microtomilli());
	while (philo->data->die_flag == 0)
	{
		if (philo->data->die_flag == 1)
			break ;
		pick_fork(philo);
		if (philo->data->die_flag == 1)
			break ;
		meal_time(philo);
		if (philo->data->die_flag == 1)
			break ;
		sleep_time(philo);
		if (philo->data->die_flag == 1)
			break ;
		think_time(philo);
		usleep(100);
	}
	return (NULL);
}

int	philoshopers(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_create(
			&data->tid[i], NULL, philo_process, &philo[i]);
	}
	i = -1;
	while (++i < data->num_of_philos)
		pthread_detach(data->tid[i]);
	while (1)
	{
		if (data->die_flag == 1 || data->must_flag == data->num_of_philos)
			break ;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;

	if (init_data(&data, argc, argv) == -1)
	{
		printf("wrong argument.\n");
		return (0);
	}
	if (init_philo(&data, &philo))
	{
		printf("init philo error\n");
		return (0);
	}
	if (init_thread(&data))
	{
		printf("init thread error\n");
		return (0);
	}
	philoshopers(&data, philo);
	return (0);
}
