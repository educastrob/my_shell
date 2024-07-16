/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:17:57 by educastro         #+#    #+#             */
/*   Updated: 2024/07/16 18:58:52 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

// libs
# include "../libft/libft.h"
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
enum e_token
{
	WORD,
	PIPE,
	REDIRECT_INPUT,
	REDIRECT_HEREDOC,
	REDIRECT_OUTPUT,
	REDIRECT_OUTPUT_APPEND,
	OR,
	AND,
	OPEN_PARENTHESIS,
	CLOSE_PARENTHESIS,
	EXPRESSION,
	COMMAND,
	SUBSHELL
};

// structs
typedef struct		s_token
{
	char			*lexeme;
	int				type;
}	t_token;

typedef struct		s_token_list
{
	t_token_list	*next;
	t_token			token;
}	t_token_list;

typedef struct		s_aux_token
{
	int		i;
	int		lexeme_length;
	int		str_length;
}	t_aux_token

// get_states.c
int		get_token_type(int state)
// tokenizer.c
t_token_list	*token_create_node(char *lexeme, int token_type);

#endif