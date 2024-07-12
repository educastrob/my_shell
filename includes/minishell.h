/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:17:57 by educastro         #+#    #+#             */
/*   Updated: 2024/07/12 11:13:05 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// libs
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


typedef enum e_token_type
{
	WORD,
	QUOTE,
	DQUOTE,
	BLOCK,
	ARCHIVE,
	PIPE,
	HEREDOC,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	OR,
	AND,
	EXEC
}					t_token_type;

typedef struct		s_tok
{
	t_token_type	type;
	char			*data;
	struct s_tok	*prev;
	struct s_tok	*next;
	int				is_last;
}					t_tok;

#endif