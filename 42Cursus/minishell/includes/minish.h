/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:09:44 by wopark            #+#    #+#             */
/*   Updated: 2021/07/04 15:50:43 by junghwki         ###   ########.fr       */
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
# define SYNTAX_ERROR_MSG	"bash: syntax error near unexpected token"

typedef struct	s_hisnode
{
	void				*pending;
	void				*finished;
	int					idx;
	struct s_hisnode	*prev;
	struct s_hisnode	*next;
}				t_hisnode;

typedef struct	s_dllist
{
	t_hisnode	*head;
	t_hisnode	*tail;
	int			length;
}				t_dllist;

t_hisnode		*ft_dll_newhisnode(void *pending, void *finished);
void			ft_dll_init(t_dllist *list);
void			ft_dll_addhisnode(
	t_dllist *list, void *pending, void *finished);
void			ft_dll_delhisnode(
	t_dllist *list, t_hisnode *node, void (*del)(void *, void *));

typedef struct	s_cursor
{
	int			r_nbr;
	int			idx;
	int			buf;
	int			key_pos;
	int			len;
	char		*pending;
	char		*finished;
	t_hisnode	*cur;
}				t_cursor;

typedef struct	s_redir
{
	int			sign;
	char		*file_name;
}				t_redir;

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

typedef struct	s_cmd
{
	char		**argv;
	int			flag;
	char		quote;
	int			fd[2];
	int			rd_fd[2];
	t_list		*rd_lst;
}				t_cmd;

typedef struct	s_data
{
	t_list		*last_node;
	char		*buf;
	char		*rd_buf;
	t_cmd		cmd;
	t_redir		rd;
	int			buf_size;
	int			input_idx;
	int			buf_idx;
	int			rd_buf_idx;
}				t_data;

typedef struct	s_archive
{
	t_list		*envv_lst;
	int			exit_stat;
}				t_archive;

t_archive		g_archive;

t_cursor		*get_cursor(void);
void			cursor_init(t_cursor *cursor, t_dllist *h_list);
int				find_prev_history(t_dllist *h_list, t_cursor *cursor);
int				find_next_history(t_dllist *h_list, t_cursor *cursor);
void			chk_space_flag(char **strs);
int				lst_add_cmd(t_data *data, t_list **cmd_root, int flag);
int				parse_error_msg(char *msg);
void			signal_init(int argc, char **argv);
int				term_key_handler(
	t_cursor *cursor, t_dllist *h_list, char **input);
void			ft_freehistory(void *pending, void *finished);
void			term_init(struct termios *term, struct termios *backup);
void			free_cmd_lst(t_list *cmd_root);
int				error_buf_free(t_data *data);
void			input_term(int buf);
int				chk_question_mark(t_data *data, char *input);
int				chk_var_name(t_data *data, char *input);
int				clensing_env_name(t_data *data, char *input, int len);
void			parse_init(t_data *data, t_list **cmd_root, int input_size);
int				parse_input(char *input);
void			update_redir(t_data *data);
int				chk_redir_sign(char *input, t_data *data);
void			init_redir(t_data *data);
void			init_cmd(t_data *data);
void			init_data(t_data *data, t_list **cmd_root, int input_size);
void			init_redir(t_data *data);
char			*realloc_input(char *ptr, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_pwd();
void			ft_cd(t_cmd *cmd);
void			ft_echo(t_cmd *cmd);
void			envv_lst_make(char **envv);
int				ft_strcmp(const char *s1, const char *s2);
void			env_swap(t_env *a, t_env *b);
t_list			*get_curr_envv_lst(char *key_value);
t_list			*get_prev_envv_lst(char *key_value);
t_env			*envv_sep(char *envv);
t_env			*env_dup(t_env *content);
void			envv_content_del(t_env *content);
void			execute_cmd(t_list *cmd_root);
void			export_lst_print();
void			export_add(t_cmd *cmd);
void			env_lst_print();
void			ft_unset(t_cmd *cmd);
void			other_command(t_cmd *cmd, char **envp);
void			free_array(char **array);
void			child_process(t_cmd *cmd, char **envp);
char			**make_envp(void);
int				env_key_check(char *key);
int				env_lst_cmp(char *s1, char *s2);
void			export_lst_sort(t_list **lst);
void			ft_exit(t_cmd *cmd, int pipe_flag);
void			err_msg_print(char *str, int exit_stat);
int				check_rd_sign(t_cmd *cmd, t_redir *rd);
int				count_pipe(t_list *list);
int				check_builtin(t_cmd *cmd, int pipe_flag);
void			lets_fork(pid_t *pid, t_cmd *cmd, t_cmd *next_cmd, int idx);
void			builtin(t_cmd *cmd, int pipe_flag);
t_cmd			*make_pipe(t_list *temp, t_cmd *cmd, int *idx, pid_t *pid);
#endif
