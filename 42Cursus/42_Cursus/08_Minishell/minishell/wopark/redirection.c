/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:59:29 by wopark            #+#    #+#             */
/*   Updated: 2021/07/02 16:32:22 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void	update_redir(t_data *data)
{
	t_cmd	*tmp_cmd;
	t_redir	*tmp_rd;
	int		i;

	tmp_cmd = data->last_node->content;
	tmp_rd = (t_redir *)malloc(sizeof(t_redir));
	tmp_rd->sign = data->rd.sign;
	tmp_rd->file_name = ft_strtrim(data->rd_buf, " ");
	free(data->rd_buf);
	i = 0;
	while (tmp_rd->file_name[i])
	{
		if (tmp_rd->file_name[i] == -1)
			tmp_rd->file_name[i] = ' ';
		i++;
	}
	data->rd_buf = ft_calloc(sizeof(char), data->buf_size);
	data->rd_buf_idx = 0;
	data->rd.sign = 0;
	ft_lstadd_back(&tmp_cmd->rd_lst, ft_lstnew(tmp_rd));
	data->rd.file_name = 0;
	data->rd.sign = 0;
}

int		left_redir_sign(t_data *data)
{
	if (data->rd.sign == 0 || (data->rd.sign == 1 && !*data->rd_buf))
		data->rd.sign++;
	else if ((data->rd.sign == 2 || data->rd.sign == 1) && *data->rd_buf)
	{
		update_redir(data);
		data->input_idx--;
	}
	else if (data->rd.sign == -1 && *data->rd_buf)
	{
		update_redir(data);
		data->input_idx--;
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int		right_redir_sign(t_data *data)
{
	if (data->rd.sign == 0)
		data->rd.sign--;
	else if ((data->rd.sign == 2 || data->rd.sign == 1) && *data->rd_buf)
	{
		update_redir(data);
		data->input_idx--;
	}
	else if (data->rd.sign == -1 && *data->rd_buf)
	{
		update_redir(data);
		data->input_idx--;
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int		chk_redir_sign(char *input, t_data *data)
{
	if (input[data->input_idx] == '>')
		return (left_redir_sign(data));
	else if (input[data->input_idx] == '<')
		return (right_redir_sign(data));
	else
		return (ERROR);
	return (SUCCESS);
}
