/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:19:23 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 00:19:26 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int res;

	if (nb < 0)
		return (0);
	i = 1;
	res = 1;
	while (i <= nb)
		res *= i++;
	return (res);
}
