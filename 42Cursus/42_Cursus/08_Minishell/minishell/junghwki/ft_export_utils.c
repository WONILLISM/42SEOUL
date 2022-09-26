/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 08:51:37 by junghwki          #+#    #+#             */
/*   Updated: 2021/06/30 08:51:38 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			env_key_check(char *key)
{
	int		idx;

	idx = 0;
	if (!key[idx] || ft_isdigit(key[idx]))
		return (-1);
	while (key[idx])
	{
		if (key[idx] == '_' || ft_isalnum(key[idx]))
			idx++;
		else
			return (-1);
	}
	return (0);
}

int			env_lst_cmp(char *s1, char *s2)
{
	int		idx;

	idx = 0;
	while (s1[idx])
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (-1);
}

void		export_lst_sort(t_list **lst)
{
	t_list	*temp;
	t_env	*temp_env;
	t_list	*next_temp;
	t_env	*next_temp_env;

	temp = (*lst)->next;
	while (temp)
	{
		temp_env = temp->content;
		next_temp = temp->next;
		while (next_temp)
		{
			next_temp_env = next_temp->content;
			if (env_lst_cmp(temp_env->key, next_temp_env->key) > 0)
				env_swap(temp_env, next_temp_env);
			next_temp = next_temp->next;
		}
		temp = temp->next;
	}
}
