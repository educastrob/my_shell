/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:44:40 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/22 20:56:33 by educastro        ###   ########.fr       */
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

int		get_state_1(char c)
{
	int	next_state;

	if (is_whitespace(c) || c == '\0')
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

int		get_state_40(char c)
{
	int	state;

	if (c == '|')
		state = 41;
	else if (c != '|')
		state = 42;
	else
		state = -1;
	return (state);
}

int		get_state_50(char c)
{
	int	state;

	if (c == '&')
		state = 51;
	else if (c != '&')
		state = -1;
	else
		state = -1;
	return (state);
}

int		get_state_60(char c)
{
	int	state;

	if (c == '<')
		state = 61;
	else if (c != '<')
		state = 62;
	else
		state = -1;
	return (state);
}

int		get_state_70(char c)
{
	int	state;

	if (c == '>')
		state = 71;
	else if (c != '>')
		state = 72;
	else
		state = -1;
	return (state);
}

int		get_next_state(int state, char c)
{
	int	next_state;

	if (state == 1)
		next_state = get_state_1(c);
	else if (state == 40)
		next_state = get_state_40(c);
	else if (state == 50)
		next_state = get_state_50(c);
	else if (state == 60)
		next_state = get_state_60(c);
	else if (state == 70)
		next_state = get_state_70(c);
	else
		next_state = -1;
	return (next_state);
}