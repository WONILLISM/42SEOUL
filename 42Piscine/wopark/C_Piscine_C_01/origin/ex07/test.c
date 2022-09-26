/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:20:32 by wopark            #+#    #+#             */
/*   Updated: 2020/08/04 17:35:55 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int left;
	int right;
	int tmp;

	left = 0;
	right = size - 1;
	while (left < size / 2)
	{
		tmp = tab[left];
		tab[left] = tab[right - left];
		tab[right - left] = tmp;
		++left;
	}
}

void print_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
}

int		main(void)
{
	const int size = 10;
	int tab[size];
	int i;

	i = 0;
	while (i < size)
	{
		tab[i] = i;
		i++;
	}
	print_arr(tab, size);
	ft_rev_int_tab(tab, size);
	print_arr(tab, size);

	return (0);
}
