/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:24:35 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/02 20:29:04 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void		env_value_print(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		if (ft_strchr("$`\\\"", str[idx]))
			write(1, "\\", 1);
		write(1, &str[idx], 1);
		idx++;
	}
}

t_list		*export_lst_make(void)
{
	t_env	*content;
	t_list	*export_head;
	t_list	*temp;

	export_head = ft_lstnew(NULL);
	temp = g_archive.envv_lst->next;
	while (temp)
	{
		content = env_dup(temp->content);
		ft_lstadd_back(&export_head, ft_lstnew(content));
		temp = temp->next;
	}
	return (export_head);
}

void		export_lst_print(void)
{
	void	(*del)();
	t_list	*head;
	t_list	*temp;
	t_env	*temp_env;

	del = envv_content_del;
	head = export_lst_make();
	export_lst_sort(&head);
	temp = head->next;
	while (temp)
	{
		temp_env = temp->content;
		write(1, "declare -x ", 11);
		write(1, temp_env->key, ft_strlen(temp_env->key));
		if (temp_env->value)
		{
			write(1, "=\"", 2);
			env_value_print(temp_env->value);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		temp = temp->next;
	}
	ft_lstclear(&head->next, del);
	free(head);
}

void		export_add_err(t_env *content)
{
	write(2, "minish: export: `", 17);
	write(2, content->key, ft_strlen(content->key));
	if (content->value)
	{
		write(2, "=", 1);
		write(2, content->value, ft_strlen(content->value));
	}
	err_msg_print("': not a valid identifier\n", 1);
	envv_content_del(content);
}

void		export_add(t_cmd *cmd)
{
	t_list	*temp;
	t_env	*content;
	int		idx;

	idx = 1;
	while (cmd->argv[idx])
	{
		content = envv_sep(cmd->argv[idx]);
		if (env_key_check(content->key) < 0)
			export_add_err(content);
		else
		{
			temp = get_curr_envv_lst(content->key);
			if (temp && content->value)
			{
				envv_content_del(temp->content);
				temp->content = content;
			}
			else if (!temp)
				ft_lstadd_back(&g_archive.envv_lst, ft_lstnew(content));
			else
				envv_content_del(content);
		}
		idx++;
	}
}
