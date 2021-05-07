#include "../includes/minish.h"

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

t_env	*env_dup(t_env *content)
{
	t_env	*ret;

	ret = (t_env *)malloc(sizeof(t_env));//free
	ret->key = ft_strdup(content->key);//free
	ret->value = ft_strdup(content->value);//free
	return (ret);
}

void			export_lst_sort(t_list **lst)
{
	t_list		*temp;
	t_env		*temp_env;
	t_list		*next_temp;
	t_env		*next_temp_env;

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

t_list			*export_lst_make()
{
	t_env		*content;
	t_list		*export_head;
	t_list		*temp;

	export_head = ft_lstnew(0);
	temp = g_envv_lst->next;
	while (temp)
	{
		content = env_dup(temp->content);
		ft_lstadd_back(&export_head, ft_lstnew(content));//free
		temp = temp->next;
	}
	return (export_head);
}

void		export_lst_print()
{
	t_list	*head;
	t_list	*temp;
	t_env	*temp_env;

	head = export_lst_make();
	export_lst_sort(&head);
	temp = head->next;
	while (temp)
	{
		temp_env = temp->content;
		printf("%s=%s\n",temp_env->key,temp_env->value);
		temp = temp->next;
	}
}
