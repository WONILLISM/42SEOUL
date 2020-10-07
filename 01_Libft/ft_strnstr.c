/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:27:12 by wopark            #+#    #+#             */
/*   Updated: 2020/10/07 19:37:03 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;
	size_t	blen;
	size_t	i;

	if (!*little)
		return ((char *)big);
	llen = ft_strlen(little);
	blen = ft_strlen(big);
	i = 0;
	if (blen < llen || len < llen)
		return (0);
	while (i + llen <= len)
	{
		if (big[i] == *little && !ft_strncmp(big + i, little, llen))
			return ((char *)big + i);
		i++;
	}
	return (0);
}
