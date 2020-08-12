/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:37:59 by wopark            #+#    #+#             */
/*   Updated: 2020/08/04 18:09:33 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

void print_arr(int *arr, int size)
{
	int i = 0;

	while(i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int main(void)
{
	const int size = 10;
	int tab[size] = { 2,4,100,1,8,42,11,80,32,77 };
	
	print_arr(tab, size);
	ft_sort_int_tab(tab, size);
	print_arr(tab, size);

	return (0);
}
