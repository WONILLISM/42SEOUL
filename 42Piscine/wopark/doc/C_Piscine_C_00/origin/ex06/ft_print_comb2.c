/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:26:08 by wopark            #+#    #+#             */
/*   Updated: 2020/08/05 19:35:59 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int		g_visit[100];
int		g_start;

void	init_global(void)
{
	int i;

	g_start = 0;
	i = 0;
	while (i < 100)
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
	int k;

	i = 0;
	k = 0;
	if (!g_start)
		g_start++;
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	while (i < 100)
	{
		if (g_visit[i])
		{
			if (k)
				ft_putchar(' ');
			ft_putchar('0' + (i / 10));
			ft_putchar('0' + (i % 10));
			++k;
		}
		++i;
	}
}

void	process(int j, int cnt)
{
	int i;

	if (cnt == 2)
	{
		result();
		return ;
	}
	i = j;
	while (i < 100)
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

void	ft_print_comb2(void)
{
	init_global();
	process(0, 0);
}
