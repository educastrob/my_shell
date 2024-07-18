/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:17:57 by educastro         #+#    #+#             */
/*   Updated: 2024/07/18 16:52:59 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

// libs
# include "minishell.h"

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
typedef struct			s_token
{
	char				*lexeme;
	int					type;
}	t_token;

typedef struct			s_token_list
{
	struct s_token_list	*next;
	t_token				token;
}	t_token_list;

typedef struct			s_aux_token
{
	int					token_type;
	int					state;
	int					i;
	int					lexeme_length;
	int					str_length;
}	t_aux_token;

// get_states.c
int		get_token_type(int state);

// tokenizer.c
t_token_list	*get_token_list(char *str)

#endif