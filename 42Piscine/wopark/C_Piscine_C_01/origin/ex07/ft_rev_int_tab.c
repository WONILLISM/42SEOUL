/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:20:32 by wopark            #+#    #+#             */
/*   Updated: 2020/08/04 17:36:27 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
