/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 00:35:29 by wopark            #+#    #+#             */
/*   Updated: 2020/08/06 00:39:56 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		chk_upcase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		chk_locase(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!chk_locase(str[i]))
		{
			if (chk_upcase(str[i]))
			{
				str[i] = str[i] - 'A' + 'a';
			}
		}
		++i;
	}
	str[i] = '\0';
	return (str);
}
