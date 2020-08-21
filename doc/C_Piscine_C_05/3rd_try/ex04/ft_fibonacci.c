/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:20:09 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 00:20:54 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tail_recursive(int pprev, int prev, int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (pprev);
	if (n == 1)
		return (prev);
	return (ft_tail_recursive(prev, (pprev + prev), n - 1));
}

int		ft_fibonacci(int index)
{
	return (ft_tail_recursive(0, 1, index));
}
