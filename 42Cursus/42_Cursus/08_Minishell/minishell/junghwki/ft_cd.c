/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:24:45 by junghwki          #+#    #+#             */
/*   Updated: 2021/06/29 22:13:05 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void		change_pwd(void)
{
	char	*path;
	t_list	*temp;
	t_env	*temp_env;

	temp = get_curr_envv_lst("PWD");
	if (temp)
	{
		path = NULL;
		path = getcwd(NULL, 0);
		if (path == NULL)
			printf("ft_cd path Error\n");
		else
		{
			temp_env = temp->content;
			if (temp_env->value)
				free(temp_env->value);
			temp_env->value = ft_strdup(path);
		}
		if (path)
			free(path);
	}
	g_archive.exit_stat = 0;
}

void		ft_cd(t_cmd *cmd)
{
	int		ret_value;

	ret_value = chdir(cmd->argv[1]);
	if (ret_value < 0)
	{
		write(2, "minish: cd: ", 12);
		if (cmd->argv[1])
			write(2, cmd->argv[1], ft_strlen(cmd->argv[1]));
		err_msg_print(": No such file or directory\n", 1);
	}
	else
		change_pwd();
}
