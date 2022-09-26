/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:40:20 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 12:40:20 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int		*ft_range(int min, int max)
{
	int *ret;
	int size;
	int i;

	if ((size = max - min) <= 0)
		return (0);
	if (!(ret = (int *)malloc(sizeof(int) * size)))
		return  (0);
	i = 0;
	while (i < size)
	{
		ret[i] = min + i;
		i++;
	}
	return (ret);
}
