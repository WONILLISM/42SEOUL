/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonilpark <wonilpark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:43:21 by wopark            #+#    #+#             */
/*   Updated: 2021/08/06 19:33:33 by wonilpark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_thread(t_data *data)
{
	int	i;

	i = -1;
	data->cur_time = 0;
	data->die_flag = 0;
	data->must_flag = 0;
	data->mid = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (data->mid == NULL)
		return (-1);
	while (++i < data->num_of_philos)
		pthread_mutex_init(&data->mid[i], NULL);
	data->tid = (pthread_t *)
		malloc(sizeof(pthread_t) * data->num_of_philos);
	pthread_mutex_init(&data->print, NULL);
	data->start_time = microtomilli();
	if (data->tid == NULL)
		return (-1);
	return (0);
}

int	check_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	init_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		while (++i < argc)
		{
			if (!check_arg(argv[i]))
				return (-1);
		}
		data->num_of_philos = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		data->time_must_eat = 0;
		if (argc == 6)
			data->time_must_eat = ft_atoi(argv[5]);
	}
	else
		return (-1);
	return (0);
}

int	init_philo(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philos);
	if (*philo == NULL)
		return (-1);
	while (i < data->num_of_philos)
	{
		(*philo)[i].idx = i + 1;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].left_fork_idx = \
			(data->num_of_philos + i - 1) % data->num_of_philos + 1;
		if ((*philo)[i].idx == data->num_of_philos)
			(*philo)[i].right_fork_idx = data->num_of_philos;
		else
			(*philo)[i].right_fork_idx = \
				(data->num_of_philos + i + 1) % data->num_of_philos;
		(*philo)[i].status = 0;
		(*philo)[i].last_eat_time = microtomilli();
		(*philo)[i].data = data;
		i++;
	}
	return (0);
}
