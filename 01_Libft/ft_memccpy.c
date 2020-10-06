/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:20:50 by wopark            #+#    #+#             */
/*   Updated: 2020/10/06 16:34:33 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (i < n && ((unsigned char *)src)[i] && !flag)
	{
		flag = ((unsigned char *)src)[i] == ((unsigned char)c) ? 1 : 0;
		i++;
	}
	if (flag)
	{
		ft_memcpy(dst, src, i);
		return (dst + i);
	}
	else
	{
		ft_memcpy(dst, src, n);
		return (0);
	}
}
/*
** line 24 : 삼항연산자 결과값 주위 공백 (norm check)
*/
