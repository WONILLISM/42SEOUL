/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:55:30 by wopark            #+#    #+#             */
/*   Updated: 2020/08/05 19:31:29 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int		g_visit[10];
int		g_start;

void	init_global(void)
{
	int i;

	g_start = 0;
	i = 0;
	while (i < 10)
	{
		g_visit[i] = 0;
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	result(void)
{
	int i;

	i = 0;
	if (!g_start)
		g_start++;
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	while (i < 10)
	{
		if (g_visit[i])
			ft_putchar('0' + i);
		++i;
	}
}

void	process(int j, int cnt)
{
	int i;

	i = j;
	if (cnt == 3)
	{
		result();
		return ;
	}
	while (i < 10)
	{
		if (!g_visit[i])
		{
			g_visit[i] = 1;
			process(i, cnt + 1);
			g_visit[i] = 0;
		}
		++i;
	}
}

void	ft_print_comb(void)
{
	init_global();
	process(0, 0);
}
