/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:00:56 by wopark            #+#    #+#             */
/*   Updated: 2021/07/27 19:00:58 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	long			start_time;
	long			cur_time;
	int				die_flag;
	int				must_flag;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	pthread_t		*tid;
	pthread_mutex_t	*mid;
	pthread_mutex_t	print;
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	int				status;
	int				idx;
	int				left_fork_idx;
	int				right_fork_idx;
	int				eat_cnt;
	long			last_eat_time;
}					t_philo;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		init_thread(t_data *data);
int		init_data(t_data *data, int argc, char **argv);
int		init_philo(t_data *data, t_philo **philo);
long	microtomilli(void);
void	ft_sleep(long t, long cur);
void	pick_fork(t_philo *philo);
void	meal_time(t_philo *philo);
void	sleep_time(t_philo *philo);
void	think_time(t_philo *philo);
#endif
