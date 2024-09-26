/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:40:49 by edcastro          #+#    #+#             */
/*   Updated: 2024/09/26 16:22:25 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H

// libs
# include "../libft/libft.h"
# include "environment.h"
# include "parsing.h"
# include "tokenizer.h"
# include "expander.h"
# include "executor.h"

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "fcntl.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

// global
extern volatile int	g_signal;

// typedefs
typedef struct s_env t_env;
typedef struct s_token_list t_token_list;
typedef struct s_tree t_tree;

// enums
enum	e_bool
{
	FALSE,
	TRUE
};

// structs
typedef struct	s_minishell
{
	t_tree			*tree;
	t_list			*envs;
	t_token_list	*token_list;
}				t_minishell;

// builtins
int	env(t_minishell *minishell);
int	pwd(void);
int	ft_echo(char **args);

#endif
