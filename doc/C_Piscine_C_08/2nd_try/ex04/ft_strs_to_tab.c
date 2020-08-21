/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:45:46 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 14:45:48 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void					ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

struct s_stock_str		*ft_strs_to_tab(int argc, char **argv)
{
	int			i;
	t_stock_str *answer;

	answer = (t_stock_str *)malloc(sizeof(t_stock_str) * (argc + 1));
	if (answer == 0)
		return (0);
	i = 0;
	while (i < argc)
	{
		answer[i].size = ft_strlen(argv[i]);
		answer[i].str = (char *)malloc(answer[i].size + 1);
		ft_strcpy(answer[i].str, argv[i]);
		answer[i].copy = (char *)malloc(answer[i].size + 1);
		ft_strcpy(answer[i].copy, argv[i]);
		i++;
	}
	answer[i].str = 0;
	return (answer);
}
