/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strltrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:10:26 by wopark            #+#    #+#             */
/*   Updated: 2021/07/04 17:01:37 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strltrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	len = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (!(res = (char *)malloc(sizeof(char) * (len - start + 1))))
		return (NULL);
	ft_strlcpy(res, s1 + start, len - start + 1);
	return (res);
}
