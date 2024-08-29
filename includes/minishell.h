/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:40:49 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/29 20:00:36 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H

// libs
# include "../libft/libft.h"
# include "expander.h"
# include "lexing.h"

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

typedef struct s_token_list t_token_list;

// enums
enum	e_bool
{
	FALSE,
	TRUE
};

// structs
typedef struct	s_minishell
{
	t_token_list	*tokens;
	t_list			*envs;
}				t_minishell;

// builtins
int	env(t_minishell *minishell);
int	pwd(void);

#endif
