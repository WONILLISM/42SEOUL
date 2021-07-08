/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:07:25 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/02 18:07:28 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			check_rd_sign(t_cmd *cmd, t_redir *rd)
{
	if (rd->sign == -1)
	{
		if (cmd->rd_fd[0] > 0)
			close(cmd->rd_fd[0]);
		cmd->rd_fd[0] = open(rd->file_name, O_RDONLY, 0644);
		if (cmd->rd_fd[0] < 0)
		{
			write(2, "minish: ", 8);
			write(2, rd->file_name, ft_strlen(rd->file_name));
			err_msg_print(": No such file or directory\n", 1);
			return (0);
		}
	}
	else if (rd->sign == 1 || rd->sign == 2)
	{
		if (cmd->rd_fd[1] > 0)
			close(cmd->rd_fd[1]);
		if (rd->sign == 1)
			cmd->rd_fd[1] = open(rd->file_name,
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else
			cmd->rd_fd[1] = open(rd->file_name,
			O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	return (1);
}

int			count_pipe(t_list *list)
{
	t_cmd	*cmd;
	int		ret;

	ret = 0;
	while (list)
	{
		cmd = list->content;
		if (cmd->flag == 1)
			ret++;
		else
			return (ret);
		list = list->next;
	}
	write(2, "Error\n", 6);
	return (-1);
}

int			check_builtin(t_cmd *cmd, int pipe_flag)
{
	if (ft_strcmp(cmd->argv[0], "cd") == 0)
		ft_cd(cmd);
	else if (ft_strcmp(cmd->argv[0], "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		if (!cmd->argv[1])
			export_lst_print();
		else
			export_add(cmd);
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		ft_unset(cmd);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		env_lst_print();
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		ft_exit(cmd, pipe_flag);
	else
		return (1);
	return (0);
}

void		lets_fork(pid_t *pid, t_cmd *cmd, t_cmd *next_cmd, int idx)
{
	*pid = fork();
	if (*pid < 0)
		write(2, "\n", 6);
	else if (*pid == 0)
	{
		if (cmd->flag == 1)
		{
			close(next_cmd->fd[0]);
			if (idx != 0)
				dup2(cmd->fd[0], 0);
			dup2(next_cmd->fd[1], 1);
		}
		else
			dup2(cmd->fd[0], 0);
		builtin(cmd, 1);
		exit(g_archive.exit_stat);
	}
	else
	{
		close(cmd->fd[0]);
		close(next_cmd->fd[1]);
	}
}

t_cmd		*make_pipe(t_list *temp, t_cmd *cmd, int *idx, pid_t *pid)
{
	t_cmd	*next_cmd;

	next_cmd = NULL;
	if (*idx == -1)
	{
		pipe(cmd->fd);
		close(cmd->fd[1]);
	}
	if (temp->next)
	{
		next_cmd = temp->next->content;
		pipe(next_cmd->fd);
	}
	(*idx)++;
	lets_fork(&pid[*idx], cmd, next_cmd, *idx);
	return (next_cmd);
}
