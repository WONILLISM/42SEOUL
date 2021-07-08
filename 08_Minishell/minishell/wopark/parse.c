/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:31:59 by wopark            #+#    #+#             */
/*   Updated: 2021/07/02 20:54:35 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		parse_envv_handler(t_data *data, char *input)
{
	int		len;

	data->input_idx++;
	if (chk_question_mark(data, input))
		return (0);
	len = chk_var_name(data, input);
	if (len == 0)
		return (0);
	return (clensing_env_name(data, input, len));
}

void	parse_get_data2(char *input, t_data *data)
{
	if (data->cmd.quote && input[data->input_idx] == ' ')
		input[data->input_idx] = -1;
	if (data->cmd.quote != '\'' && input[data->input_idx] == '\\'
		&& input[data->input_idx + 1])
	{
		if (data->cmd.quote == '\"'
			&& ft_strchr("$`\"\\", input[data->input_idx + 1]))
			data->input_idx++;
		if (data->cmd.quote == 0)
			data->input_idx++;
		if (input[data->input_idx] == ' ')
			input[data->input_idx] = -1;
	}
	if (data->rd.sign && input[data->input_idx] != ' ')
		data->rd_buf[data->rd_buf_idx++] = input[data->input_idx];
	else
		data->buf[data->buf_idx++] = input[data->input_idx];
}

int		parse_get_data(char *input, t_data *data, t_list **cmd_root)
{
	if (data->cmd.quote == input[data->input_idx])
		data->cmd.quote = 0;
	else if (data->cmd.quote == 0
		&& *data->rd_buf != 0 && input[data->input_idx] == ' ')
		update_redir(data);
	else if (data->cmd.quote == 0 && input[data->input_idx] == '\"')
		data->cmd.quote = input[data->input_idx];
	else if (data->cmd.quote == 0 && input[data->input_idx] == '\'')
		data->cmd.quote = input[data->input_idx];
	else if (data->cmd.quote == 0 && input[data->input_idx] == ';')
		return (lst_add_cmd(data, cmd_root, 0));
	else if (data->cmd.quote == 0 && input[data->input_idx] == '|')
		return (lst_add_cmd(data, cmd_root, 1));
	else if (data->cmd.quote != '\'' && input[data->input_idx] == '$')
		return (parse_envv_handler(data, input));
	else if (data->cmd.quote == 0 && ft_strchr("><", input[data->input_idx]))
		chk_redir_sign(input, data);
	else
		parse_get_data2(input, data);
	return (0);
}

int		parse_loop(
	char *input, t_data *data, t_list **cmd_root, int *parse_error)
{
	char	*input_tmp;

	input_tmp = ft_strltrim(input, " ");
	parse_init(data, cmd_root, ft_strlen(input));
	while (input_tmp[++data->input_idx])
	{
		*parse_error = parse_get_data(input_tmp, data, cmd_root);
		if (*parse_error == ERROR)
		{
			free_cmd_lst(*cmd_root);
			free(input_tmp);
			return (ERROR);
		}
	}
	free(input_tmp);
	return (SUCCESS);
}

int		parse_input(char *input)
{
	t_data	data;
	t_list	*cmd_root;
	int		parse_error;

	parse_error = 1;
	if (input)
	{
		if (parse_loop(input, &data, &cmd_root, &parse_error) == ERROR)
			return (ERROR);
		if (parse_error != -1)
			parse_error = lst_add_cmd(&data, &cmd_root, -1);
		if (parse_error == -1)
		{
			free_cmd_lst(cmd_root);
			return (ERROR);
		}
		else
			execute_cmd(cmd_root);
		free_cmd_lst(cmd_root);
	}
	return (SUCCESS);
}
