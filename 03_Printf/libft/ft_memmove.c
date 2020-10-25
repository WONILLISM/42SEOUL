/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:24:13 by wopark            #+#    #+#             */
/*   Updated: 2020/10/07 19:15:47 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dst == src || !n)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst < src)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	return (dst);
}
