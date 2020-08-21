/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:43:01 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 12:55:35 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	char	*ft_convert_dec_to_base(int dec, char *base_char, int base_len);

int				ft_atoi_check(char *str, char *base_char, int base_len)
{
	int idx;

	idx = 0;
	while (idx < base_len)
	{
		if (*str == base_char[idx])
			return (1);
		idx++;
	}
	return (0);
}

int				get_base_idx(char *str, char *base_char, int base_len)
{
	int idx;

	idx = 0;
	while (idx < base_len)
	{
		if (*str == base_char[idx])
			break ;
		idx++;
	}
	return (idx);
}

int				ft_atoi(char *str, char *base_char, int base_len)
{
	int flag;
	int result;
	int temp;

	flag = 1;
	result = 0;
	temp = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	while (ft_atoi_check(str, base_char, base_len))
	{
		result *= base_len;
		temp = get_base_idx(str, base_char, base_len);
		result += temp;
		str++;
	}
	return (result * flag);
}

int				ft_check_base(char *base, int *cnt)
{
	int idx;
	int idx_check;

	*cnt = 0;
	if (!*base || !*(base + 1))
		return (0);
	idx = 0;
	while (base[idx])
	{
		if ((9 <= base[idx] && base[idx] <= 13) ||
				base[idx] == ' ' || base[idx] == '+' || base[idx] == '-')
			return (0);
		*cnt = *cnt + 1;
		idx++;
	}
	idx = 0;
	while (base[idx])
	{
		idx_check = idx + 1;
		while (base[idx_check])
			if (base[idx] == base[idx_check++])
				return (0);
		idx++;
	}
	return (1);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int dec;
	int base_from_size;
	int base_to_size;

	if (ft_check_base(base_from, &base_from_size))
	{
		dec = ft_atoi(nbr, base_from, base_from_size);
		if (ft_check_base(base_to, &base_to_size))
			return (ft_convert_dec_to_base(dec, base_to, base_to_size));
	}
	return (0);
}
