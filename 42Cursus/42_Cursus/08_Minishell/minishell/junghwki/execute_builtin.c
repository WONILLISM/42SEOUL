/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:24:26 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/02 18:04:28 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void		ft_execve(t_cmd *cmd, int pipe_flag)
{
	char	**envp;

	if (check_builtin(cmd, pipe_flag))
	{
		envp = make_envp();
		if (pipe_flag)
			child_process(cmd, envp);
		else
			other_command(cmd, envp);
		free_array(envp);
	}
}

void		redirection(t_cmd *cmd, int *temp_fd)
{
	t_list	*rd_lst;
	t_redir	*rd;

	rd_lst = cmd->rd_lst->next;
	cmd->rd_fd[0] = 0;
	cmd->rd_fd[1] = 0;
	while (rd_lst)
	{
		rd = rd_lst->content;
		if (!check_rd_sign(cmd, rd))
			break ;
		rd_lst = rd_lst->next;
	}
	if (cmd->rd_fd[0])
	{
		dup2(0, temp_fd[0]);
		dup2(cmd->rd_fd[0], 0);
	}
	if (cmd->rd_fd[1])
	{
		dup2(1, temp_fd[1]);
		dup2(cmd->rd_fd[1], 1);
	}
}

void		builtin(t_cmd *cmd, int pipe_flag)
{
	int		*temp_fd;

	temp_fd = (int *)malloc(sizeof(int) * 2);
	pipe(temp_fd);
	if (cmd->rd_lst)
		redirection(cmd, temp_fd);
	if (*(cmd->argv) && cmd->rd_fd[0] >= 0)
		ft_execve(cmd, pipe_flag);
	if (cmd->rd_lst)
	{
		if (cmd->rd_fd[1])
			dup2(temp_fd[1], 1);
		if (cmd->rd_fd[0])
			dup2(temp_fd[0], 0);
	}
	free(temp_fd);
}

t_list		*execute_pipe(t_list *temp, t_cmd *cmd, int pipe_cnt, pid_t *pid)
{
	int		idx;
	t_cmd	*next_cmd;

	idx = -1;
	while (cmd->flag == 1)
	{
		next_cmd = make_pipe(temp, cmd, &idx, pid);
		temp = temp->next;
		cmd = temp->content;
	}
	if (cmd->flag == 0)
	{
		idx++;
		lets_fork(&pid[idx], cmd, next_cmd, idx);
		while (idx >= 0)
		{
			waitpid(pid[pipe_cnt - idx], &g_archive.exit_stat, 0);
			if (g_archive.exit_stat >= 256)
				g_archive.exit_stat = g_archive.exit_stat / 256;
			idx--;
		}
	}
	return (temp);
}

void		execute_cmd(t_list *cmd_root)
{
	t_list	*temp;
	t_cmd	*cmd;
	int		pipe_cnt;
	pid_t	*pid;

	temp = cmd_root->next;
	while (temp)
	{
		cmd = temp->content;
		if (cmd->flag == 1)
		{
			pipe_cnt = count_pipe(temp);
			pid = (int *)malloc(sizeof(pid_t) * (pipe_cnt + 1));
			temp = execute_pipe(temp, cmd, pipe_cnt, pid);
			free(pid);
		}
		else
			builtin(cmd, 0);
		temp = temp->next;
	}
}
