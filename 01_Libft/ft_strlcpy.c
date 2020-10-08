/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:25:18 by wopark            #+#    #+#             */
/*   Updated: 2020/10/09 00:51:10 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*s;
	size_t		n;

	s = src;
	n = size;
	if (!dst && !src)
		return (0);
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*dst = *s) == '\0')
				break ;
			dst++;
			s++;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*s)
			s++;
	}
	return (s - src - 1);
}
/*
** 널 문자 확인 후 다음 주소로 넘어가는 경우 처리
*/
