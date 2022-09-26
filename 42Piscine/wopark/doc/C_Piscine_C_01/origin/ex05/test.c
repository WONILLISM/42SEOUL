/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:35:22 by wopark            #+#    #+#             */
/*   Updated: 2020/08/04 16:39:53 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(void)
{
	ft_putstr("Hello World!");
	return (0);
}
