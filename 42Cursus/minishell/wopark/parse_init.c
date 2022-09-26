/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:46:01 by wopark            #+#    #+#             */
/*   Updated: 2021/06/30 14:46:26 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void	init_cmd(t_data *data)
{
	data->cmd.argv = NULL;
	data->cmd.quote = 0;
	data->cmd.fd[0] = 0;
	data->cmd.fd[1] = 0;
}

void	parse_init(t_data *data, t_list **cmd_root, int input_size)
{
	t_cmd	*tmp_cmd;

	*cmd_root = ft_lstnew(NULL);
	tmp_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	tmp_cmd->argv = NULL;
	ft_lstadd_back(cmd_root, ft_lstnew(tmp_cmd));
	tmp_cmd->rd_lst = ft_lstnew(NULL);
	data->last_node = ft_lstlast(*cmd_root);
	data->last_node->next = NULL;
	data->buf_size = input_size + 1;
	data->buf = ft_calloc(data->buf_size, sizeof(char));
	data->rd_buf = ft_calloc(data->buf_size, sizeof(char));
	data->buf_idx = 0;
	data->rd_buf_idx = 0;
	data->input_idx = -1;
	data->cmd.argv = NULL;
	data->cmd.flag = 0;
	data->cmd.quote = 0;
	data->rd.file_name = NULL;
	data->rd.sign = 0;
	data->rd_buf_idx = 0;
}
