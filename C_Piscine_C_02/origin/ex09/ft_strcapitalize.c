/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:33:09 by wopark            #+#    #+#             */
/*   Updated: 2020/08/10 19:33:20 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int		is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int		first;
	int		i;

	first = 1;
	i = 0;
	while (str[i])
	{
		if (is_numeric(str[i]) || is_upper(str[i]) || is_lower(str[i]))
		{
			if (first)
			{
				if (is_lower(str[i]))
					str[i] = str[i] - 'a' + 'A';
				first = 0;
			}
			else if (is_upper(str[i]))
				str[i] = str[i] - 'A' + 'a';
		}
		else
			first = 1;
		i++;
	}
	return (str);
}
