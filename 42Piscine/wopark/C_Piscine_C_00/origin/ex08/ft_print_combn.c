/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:13:17 by wopark            #+#    #+#             */
/*   Updated: 2020/08/05 20:23:40 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

int		g_visit[10];
int		g_start;

void	init_global(void)
{
	int i;

	i = 0;
	g_start = 0;
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
	int k;

	k = 0;
	if (!g_start)
		g_start++;
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	while (k < 10)
	{
		if (g_visit[k])
			ft_putchar('0' + k);
		k++;
	}
}

void	process(int j, int cnt, int n)
{
	int i;

	if (cnt == n)
	{
		result();
		return ;
	}
	i = j;
	while (i < 10)
	{
		if (!g_visit[i])
		{
			g_visit[i] = 1;
			process(i, cnt + 1, n);
			g_visit[i] = 0;
		}
		++i;
	}
}

void	ft_print_combn(int n)
{
	init_global();
	process(0, 0, n);
}
