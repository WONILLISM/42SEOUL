/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:24:49 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/02 16:43:58 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void		run_execve(t_cmd *cmd, char *path, char **envp)
{
	char	*free_me;

	free_me = path;
	path = ft_strjoin(free_me, "/");
	free(free_me);
	free_me = path;
	path = ft_strjoin(free_me, cmd->argv[0]);
	free(free_me);
	execve(path, cmd->argv, envp);
	free(path);
}

char		**make_envp(void)
{
	t_list	*temp;
	t_env	*temp_env;
	char	**envp;
	int		idx;
	char	*free_me;

	idx = 0;
	temp = g_archive.envv_lst->next;
	envp = (char **)malloc(sizeof(char *) * (ft_lstsize(temp) + 1));
	while (temp)
	{
		temp_env = temp->content;
		free_me = ft_strjoin(temp_env->key, "=");
		envp[idx] = ft_strjoin(free_me, temp_env->value);
		free(free_me);
		temp = temp->next;
		idx++;
	}
	envp[idx] = NULL;
	return (envp);
}

void		run_in_current_path(t_cmd *cmd, char **envp)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		printf("path Error\n");
	else
	{
		if (cmd->argv[0][0] == '/')
			execve(cmd->argv[0], cmd->argv, envp);
		else
		{
			run_execve(cmd, path, envp);
		}
	}
}

void		child_process(t_cmd *cmd, char **envp)
{
	int		idx;
	t_list	*temp;
	t_env	*temp_env;
	char	**path;

	idx = 0;
	temp = get_curr_envv_lst("PATH");
	if (temp)
	{
		temp_env = temp->content;
		path = ft_split(temp_env->value, ':');
		while (path[idx])
		{
			run_execve(cmd, path[idx], envp);
			idx++;
		}
		free(path);
	}
	run_in_current_path(cmd, envp);
	write(2, "minish: ", 8);
	write(2, cmd->argv[0], ft_strlen(cmd->argv[0]));
	if (temp && cmd->argv[0][0] != '/')
		err_msg_print(": command not found\n", 127);
	else
		err_msg_print(": No such file or directory\n", 127);
}

void		other_command(t_cmd *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		write(2, "Error\n", 6);
	}
	else if (pid == 0)
	{
		child_process(cmd, envp);
		exit(g_archive.exit_stat);
	}
	else
	{
		waitpid(pid, &g_archive.exit_stat, 0);
		if (g_archive.exit_stat >= 256)
			g_archive.exit_stat = g_archive.exit_stat / 256;
	}
}
