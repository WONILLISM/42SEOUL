/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:24:03 by junghwki          #+#    #+#             */
/*   Updated: 2021/06/29 18:24:06 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void		env_swap(t_env *a, t_env *b)
{
	t_env	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_env		*envv_sep(char *envv)
{
	int		idx;
	t_env	*ret;

	idx = 0;
	ret = (t_env *)malloc(sizeof(t_env));
	while (envv[idx])
	{
		if (envv[idx] == '=')
		{
			ret->key = ft_substr(envv, 0, idx);
			ret->value = ft_strdup(&envv[idx + 1]);
			break ;
		}
		idx++;
	}
	if (envv[idx] == '\0')
	{
		ret->key = ft_substr(envv, 0, idx);
		ret->value = NULL;
	}
	return (ret);
}

void		envv_lst_make(char **envv)
{
	int		idx;
	t_env	*content;

	idx = 0;
	g_archive.envv_lst = ft_lstnew(NULL);
	while (envv[idx])
	{
		content = envv_sep(envv[idx]);
		ft_lstadd_back(&g_archive.envv_lst, ft_lstnew(content));
		idx++;
	}
}

void		env_lst_print(void)
{
	t_list	*temp;
	t_env	*temp_env;

	temp = g_archive.envv_lst->next;
	while (temp)
	{
		temp_env = temp->content;
		if (temp_env->value)
		{
			write(1, temp_env->key, ft_strlen(temp_env->key));
			write(1, "=", 1);
			write(1, temp_env->value, ft_strlen(temp_env->value));
			write(1, "\n", 1);
		}
		temp = temp->next;
	}
	g_archive.exit_stat = 0;
}
