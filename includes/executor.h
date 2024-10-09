/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:37:12 by educastro         #+#    #+#             */
/*   Updated: 2024/10/09 02:26:01 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

// libs
# include "minishell.h"
# include "environment.h"
# include "parsing.h"
# include "tokenizer.h"
# include "expander.h"
# include "../libft/libft.h"

// typedefs
typedef struct s_token_list t_token_list;
typedef struct s_minishell t_minishell;
typedef struct s_env t_env;
typedef struct s_tree t_tree;
typedef struct s_aux_tree t_aux_tree;

// structs
typedef struct s_cmd_for_fork
{
	int		fd_redir;
	int		args_num;
	int		ret_code;
	char	*cmd;
	char	**argv;
	char	**envp;
}				t_cmd_for_fork;

// signals.c
void	sig_handler_heredoc(int signal __attribute__((unused)));
void	sig_handler_sigint(int signal __attribute__((unused)));
void	sig_handler_redo_readline(int signal __attribute__((unused)));

// signals_handler.c
void	init_signals(void);
void	heredoc_signals(void);
void	execution_signals(int pid);

// signals_macros.c
int		term_by_signal(int status);
int		term_normaly(int status);
int		exit_status(int status);
int		term_signal(int status);
int		get_return_value(int status);

// exec_pipe.c
int	exec_pipe(t_tree *tree, t_minishell *data);

// exec_tree.c
int	exec_tree(t_tree *tree, t_minishell *data);

// exec_cmd.c
int	exec_cmd(t_tree *tree, t_minishell *data);

// exec_cmd_fork.c
int	exec_cmd_fork(t_tree *tree, t_minishell *data);
int	execute_command(t_tree *tree, t_minishell *data);
int	exec_execve(t_tree *tree, t_minishell *data);
int	display_error(char *cmd);

// fd_list.c
int		close_fd(int fd);
void	close_pipe(int *pipe_fd);
void	fd_list_add_fd(t_list **fd_list, int fd);
void	fd_list_close_clear(t_list **fd_list);

#endif