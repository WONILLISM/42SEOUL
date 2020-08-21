/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 02:12:16 by wopark            #+#    #+#             */
/*   Updated: 2020/08/19 02:14:02 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_i;
int		ft_atoi_base(char *str, char *base);
int		is_valid_of_base(char *base);
void	ft_nbr_to_base(int nbr, char *base, int radix, char *ret);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_radix;
	int		to_radix;
	int		tmp;
	char	*ret;

	g_i = 0;
	if (!(from_radix = is_valid_of_base(base_from)))
		return (0);
	if (!(to_radix = is_valid_of_base(base_to)))
		return (0);
	tmp = ft_atoi_base(nbr, base_from);
	if (!(ret = (char *)malloc(sizeof(char) * 32)))
		return (0);
	ft_nbr_to_base(tmp, base_to, to_radix, ret);
	ret[g_i] = '\0';
	return (0);
}
