/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:26:13 by wopark            #+#    #+#             */
/*   Updated: 2021/06/30 14:27:00 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		error_buf_free(t_data *data)
{
	free(data->rd_buf);
	data->rd_buf = NULL;
	free(data->buf);
	data->buf = NULL;
	return (ERROR);
}

void	free_rd_lst(t_list *rdlst)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_redir	*tmp_rd;

	tmp1 = rdlst->next;
	tmp2 = rdlst->next;
	while (tmp1)
	{
		tmp_rd = tmp1->content;
		free(tmp_rd->file_name);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp_rd);
		free(tmp2);
	}
	free(rdlst);
}

void	free_cmd_lst(t_list *cmd_root)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_cmd	*tmp_cmd;
	int		i;

	tmp1 = cmd_root->next;
	while (tmp1)
	{
		tmp_cmd = tmp1->content;
		i = -1;
		if (tmp_cmd->argv)
		{
			while (tmp_cmd->argv[++i])
				free(tmp_cmd->argv[i]);
			free(tmp_cmd->argv);
		}
		free_rd_lst(tmp_cmd->rd_lst);
		free(tmp_cmd);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	free(cmd_root);
}
