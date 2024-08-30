/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:17:57 by educastro         #+#    #+#             */
/*   Updated: 2024/08/30 18:59:36 by edcastro         ###   ########.fr       */
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
	EXPRESSION,
	COMMAND,
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
	struct s_token_list	*prev;
	t_token				token;
}	t_token_list;

typedef struct			s_aux_token
{
	int					token_type;
	int					state;
	int					i;
	int					lexeme_length;
	int					str_length;
	char				*lexeme;
}	t_aux_token;

// get_states.c
int				get_token_type(int state);
int				token_get_next_state(int state, char c);
int				token_state_requires_backtrack(int state);
int				token_state_is_final(int state);

// token_states_1.c
int				get_state_1(char c);
int				get_state_40(char c);
int				get_state_50(char c);
int				get_state_60(char c);
int				get_state_70(char c);

// token_states_2.c
int				get_state_80(char c);
int				get_state_81(char c);
int				get_state_82(char c);

// tokenizer.c
t_token_list	*get_token_list(char *str);
t_token_list	*token_get_sublist(t_token_list *token_lst, int start, int lst_len);
void			token_final_state(t_aux_token *aux, t_token_list **token_list, char *str);

// utils.c
void	token_clear_list(t_token_list **token_list);
int		is_whitespace(char c);
int		is_metacharacter(char c);

// tests.c (TEMPORARY)
const char *get_token_type_string(enum e_token type);
void print_token_list(t_token_list *token_list);

#endif