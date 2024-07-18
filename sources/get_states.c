/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:44:40 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/18 17:59:53 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

int		get_token_type(int state)
{
	int	type;

	if (state == 20)
		type = OPEN_PARENTHESIS;
	else if (state == 30)
		type = CLOSE_PARENTHESIS;
	else if (state == 41)
		type = OR;
	else if (state == 42)
		type = PIPE;
	else if (state == 51)
		type = AND;
	else if (state == 61)
		type = REDIRECT_HEREDOC;
	else if (state == 62)
		type = REDIRECT_INPUT;
	else if (state == 71)
		type = REDIRECT_OUTPUT_APPEND;
	else if (state == 72)
		type = REDIRECT_OUTPUT;
	else if (state == 83)
		type = WORD;
	else
		type = -1;
	return (type);
}

int		get_next_state_1(char c)
{
	int	next_state;

	if (is_whitespace(c))
		next_state = 1;
	else if (c == '(')
		next_state = 20;
	else if (c == ')')
		next_state = 30;
	else if (c == '|')
		next_state = 40;
	else if (c == '&')
		next_state = 50;
	else if (c == '<')
		next_state = 60;
	else if (c == '>')
		next_state = 70;
	else if (c == '\'')
		next_state = 81;
	else if (c == '\"')
		next_state = 82;
	else
		next_state = 80;

	return (next_state);
}

int		get_next_state(int state, char c)
{
	int	next_state;

	if (state == 1)
		next_state = get_next_state_1(c);
	else
		next_state = -1;
	return (next_state);
}