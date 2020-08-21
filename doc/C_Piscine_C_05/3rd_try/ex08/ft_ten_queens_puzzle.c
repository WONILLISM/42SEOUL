/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:20:44 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 00:29:04 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		g_row[10];
int		g_right_up[20];
int		g_left_up[20];
int		g_cnt;
char	g_ans[11];

void	process(int r)
{
	int i;

	if (r == 10)
	{
		g_cnt++;
		write(1, g_ans, 10);
		write(1, "\n", 1);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (!g_row[i] && !g_right_up[r + i] && !g_left_up[10 + (r - i) - 1])
		{
			g_row[i] = 1;
			g_right_up[r + i] = 1;
			g_left_up[10 + (r - i) - 1] = 1;
			g_ans[r] = i + '0';
			process(r + 1);
			g_row[i] = 0;
			g_right_up[r + i] = 0;
			g_left_up[10 + (r - i) - 1] = 0;
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	process(0);
	return (g_cnt);
}
