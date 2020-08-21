/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 01:49:37 by wopark            #+#    #+#             */
/*   Updated: 2020/08/20 14:14:29 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ret;
	int size;
	int i;

	if ((size = max - min) < 0)
		return (0);
	i = 0;
	if (!(ret = (int *)malloc(sizeof(int) * size)))
		return (0);
	while (i < size)
		ret[i++] = min++;
	return (ret);
}
