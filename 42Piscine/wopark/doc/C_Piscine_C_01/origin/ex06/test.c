/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:41:27 by wopark            #+#    #+#             */
/*   Updated: 2020/08/04 16:47:24 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>

int	ft_strlen(char *str)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (str[i++])
	{
		ret++;
	}
	return (ret - 1);
}

int	main(void)
{
	int res;

	res = ft_strlen("abcde");
	printf("%d\n", res);
	return (0);
}
