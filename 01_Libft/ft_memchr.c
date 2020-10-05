/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:20:58 by wopark            #+#    #+#             */
/*   Updated: 2020/10/05 17:21:17 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	*ptr = (unsigned char *)s;

	while (n--)
	{
		if (*ptr != ((unsigned char)c))
			ptr++;
		else
			return (ptr);
	}
	return (0);
}
