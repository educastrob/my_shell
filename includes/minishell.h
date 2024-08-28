/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:40:49 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/28 15:20:53 by edcastro         ###   ########.fr       */
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

// enums
enum	e_bool
{
	FALSE,
	TRUE
};

// structs
typedef struct	s_minishell
{
	t_list		*tokens;
	t_list		*envs;
}				t_minishell;

#endif
