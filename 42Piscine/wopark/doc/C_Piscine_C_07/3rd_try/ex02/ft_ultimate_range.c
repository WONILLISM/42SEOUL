/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:54:41 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 13:06:48 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		*temp;
	int		idx;

	if (min >= max)
		return (0);
	if (!(*range = (int *)malloc(sizeof(int) * (max - min))))
		return (-1);
	idx = 0;
	temp = *range;
	while ((min + idx) < max)
	{
		temp[idx] = min + idx;
		idx++;
	}
	return (max - min);
}
