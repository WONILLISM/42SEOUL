/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:25:18 by wopark            #+#    #+#             */
/*   Updated: 2020/10/06 16:34:53 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	idx;

	if (dst == NULL && src == NULL)
		return (0);
	src_len = ft_strlen(src);
	idx = 0;
	while (idx < src_len && idx + 1 < size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (size > 0)
		dst[idx] = '\0';
	return (src_len);
}
