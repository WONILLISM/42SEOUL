/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:25:18 by wopark            #+#    #+#             */
/*   Updated: 2020/10/10 14:58:45 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char	*s;
	size_t		n;

	s = src;
	n = size;
	if (!dest && !src)
		return (0);
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*dest = *s) == '\0')
				break ;
			dest++;
			s++;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*dest = '\0';
		while (*s)
			s++;
	}
	return (s - src);
}
