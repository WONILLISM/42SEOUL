/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonilpark <wonilpark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:52:06 by wopark            #+#    #+#             */
/*   Updated: 2021/08/06 19:36:13 by wonilpark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	microtomilli(void)
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	return (tmp.tv_sec * 1000L + tmp.tv_usec / 1000L);
}

void	ft_sleep(long t, long cur)
{
	long	res;

	res = cur + t;
	while (microtomilli() < res)
		usleep((long)(((res - microtomilli()) / 2) * 1000L));
}
