/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:12:07 by wopark            #+#    #+#             */
/*   Updated: 2020/08/15 17:35:12 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_same(char *str, char *find_ptr)
{
	while (*find_ptr && *find_ptr == *str)
	{
		find_ptr++;
		str++;
	}
	if (!*find_ptr)
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	char *ret;
	char *find_ptr;

	find_ptr = to_find;
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			ret = str;
			if (is_same(ret, find_ptr))
				return (ret);
		}
		str++;
	}
	ret = 0;
	return (ret);
}
