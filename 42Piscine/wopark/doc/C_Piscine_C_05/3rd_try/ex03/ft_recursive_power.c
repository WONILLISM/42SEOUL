/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:19:59 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 00:20:56 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tail_recursive(int n, int pow, int res)
{
	if (pow--)
		return (ft_tail_recursive(n, pow, res *= n));
	return (res);
}

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (ft_tail_recursive(nb, power, 1));
}
