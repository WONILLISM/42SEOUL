/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:09:44 by wopark            #+#    #+#             */
/*   Updated: 2021/06/03 19:26:02 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <termios.h>
# include <termcap.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

# define KEY_LEFT			4479771
# define KEY_RIGHT			4414235
# define KEY_UP				4283163
# define KEY_DOWN			4348699
# define KEY_BACKSPACE		127
# define CTRL_D				4

# define SEMICOLON			0
# define PIPE				1
# define ERROR				-1
# define SUCCESS			1
# define STDIN				0
# define STDOUT				1
# define STDERR				2
# define READ_ERR			-1
# define READ_SUC			0
# define SYNTAX_ERROR_MSG	"Syntax Error"

/*
**	double linked list
*/
typedef struct	s_dlnode
{
	void			*data;
	struct s_dlnode	*prev;
	struct s_dlnode	*next;
}				t_dlnode;

typedef struct	s_dllist
{
	t_dlnode	*head;
	t_dlnode	*tail;
	int			length;
}				t_dllist;

t_dlnode	*ft_dll_newnode(void	*data);
void		ft_dll_init(t_dllist *list);
void		ft_dll_add(t_dllist *list, void *data);
void		ft_dll_delnode(t_dllist *list, t_dlnode *node, void (*del)(void *));
t_dlnode	*ft_dll_find(t_dllist *list, void *data);
void		ft_dll_viewlst(t_dllist *list);
void		ft_dll_clear(t_dllist *list, void (*del)(void *));
void	history(t_dllist *list, char *input);

typedef struct	s_cursor
{
	int		r_nbr;
	int		idx;
	int		buf;
	int		key_pos;
	int		len;
	int		col;
	int		row;
}				t_cursor;

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

typedef struct	s_cmd
{
	char		**argv;		// 명령어 내용 NULL
	int			flag;		// 0: ; or NULL	1: pipe
	int			redir;
	char		quote;		// stack for ' or "
	int			fd[2];
}				t_cmd;

typedef struct	s_data
{
	t_list		*last_node;
	t_cmd		*cmd;
	char		*buf;
	int			buf_size;
	int			input_idx;
	int			buf_idx;
	int			cmd_idx;
}				t_data;

typedef struct	s_archive
{
	t_list	*envv_lst;
	char	*buf;
	int		exit_stat;
	int		parse_error;
}				t_archive;

t_archive	g_archive;
/*
** ************ wopark **************
*/

/*
** ************ parse_utils.c*************
*/
void	chk_space_flag(char **strs);
int		chk_var_name(t_data *data, char *input);
int		lst_add_cmd(t_data *data, t_list *cmd_root, int flag);

int		parse_error_check(t_data *data);
int		parse_error_msg(char *msg);
int		chk_question_mark(t_data *data, char *input);

void	signal_init(int argc, char **argv);

/*
** ************ terminal_handle.c ******************
*/
void	get_cursor_position(int *col, int *rows);
void	term_init(struct termios *term, struct termios *backup, t_cursor *cursor);
int		term_key_handler(t_cursor *ip_var, char **input);

/*
** ************ parse.c *************
*/
int		parse_input(char *input);

int		ft_strcmp(const char *s1, const char *s2);

void			ft_pwd();
void			ft_cd(t_cmd *cmd);
void			ft_echo(t_cmd *cmd);
void			envv_lst_make(char **envv);
/*				utils			*/
int				ft_strcmp(const char *s1, const char *s2);
void			env_swap(t_env *a, t_env *b);
t_list			*get_curr_envv_lst(char *key_value);
t_list			*get_prev_envv_lst(char *key_value);
t_env			*envv_sep(char *envv);
/*				utils			*/
void			envv_lst_del(t_env *content);
void			execute_builtin(t_list *cmd_root);
void			export_lst_print();
void			export_add(t_cmd *cmd);
void			env_lst_print();
void			ft_unset(t_cmd *cmd);
int				ft_execve(t_cmd *cmd);
void			free_array(char **array);
void			child_process(t_cmd *cmd);
#endif
