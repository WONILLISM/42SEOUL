/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:45:26 by wopark            #+#    #+#             */
/*   Updated: 2021/07/01 17:13:57 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void	chk_space_flag(char **strs)
{
	int i;
	int j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == -1)
				strs[i][j] = ' ';
			j++;
		}
		i++;
	}
}

int		clensing_data_buf(t_data *data, int flag)
{
	t_cmd	*tmp_cmd;
	char	*tmp;

	tmp_cmd = data->last_node->content;
	tmp = ft_strltrim(data->buf, " ");
	free(data->buf);
	data->buf = NULL;
	tmp_cmd->argv = ft_split(tmp, ' ');
	free(tmp);
	chk_space_flag(tmp_cmd->argv);
	if (flag == 0 || flag == -1)
	{
		if (data->cmd.flag == 1)
			return (ERROR);
		flag = 0;
	}
	tmp_cmd->flag = flag;
	tmp_cmd->fd[0] = 0;
	tmp_cmd->fd[1] = 0;
	tmp_cmd->rd_fd[0] = 0;
	tmp_cmd->rd_fd[1] = 0;
	data->cmd.flag = flag;
	init_cmd(data);
	return (0);
}

void	new_cmdlst_addback(t_data *data, t_list **cmd_root)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	ft_lstadd_back(cmd_root, ft_lstnew(tmp_cmd));
	tmp_cmd->rd_lst = ft_lstnew(NULL);
	tmp_cmd->argv = NULL;
	data->last_node = ft_lstlast(*cmd_root);
	data->last_node->next = NULL;
}

int		check_final_flag(t_data *data, int flag)
{
	if (data->cmd.quote)
		return (error_buf_free(data));
	if (flag == 0 && *data->buf == 0)
		return (error_buf_free(data));
	if (flag == 1 && *data->buf == 0)
		return (error_buf_free(data));
	if ((flag == -1 || flag == 0) && data->cmd.flag && *data->buf == 0)
		return (error_buf_free(data));
	if ((flag == -1 || flag == 0) && data->rd.sign && *data->rd_buf == 0)
		return (error_buf_free(data));
	return (SUCCESS);
}

int		lst_add_cmd(t_data *data, t_list **cmd_root, int flag)
{
	if (flag == 0 || flag == 1 || flag == -1)
	{
		if (check_final_flag(data, flag) == ERROR)
			return (ERROR);
		if (data->rd.sign)
			update_redir(data);
		clensing_data_buf(data, flag);
		if (flag == 0 || flag == 1)
		{
			new_cmdlst_addback(data, cmd_root);
			data->cmd.flag = 0;
			data->buf = ft_calloc(data->buf_size, sizeof(char));
			data->buf_idx = 0;
		}
		else
		{
			if (data->buf)
				free(data->buf);
			free(data->rd_buf);
		}
	}
	return (SUCCESS);
}
