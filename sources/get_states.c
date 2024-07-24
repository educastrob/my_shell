/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:44:40 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/23 12:46:39 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

int		token_state_is_final(int state)
{
	if (state == 20
		|| state == 30
		|| state == 41
		|| state == 42
		|| state == 51
		|| state == 61
		|| state == 62
		|| state == 71
		|| state == 72
		|| state == 83)
		return (1);
	return (0);
}

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

int	token_state_requires_backtrack(int state)
{
	if (state == 42
		|| state == 62
		|| state == 72
		|| state == 83)
		return (1);
	return (0);
}

int	token_get_next_state(int state, char c)
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
	else if (state == 80)
		next_state = get_state_80(c);
	else if (state == 81)
		next_state = get_state_81(c);
	else if (state == 82)
		next_state = get_state_82(c);
	else
		next_state = -1;
	return (next_state);
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

int		get_state_80(char c)
{
	int	state;

	if (c == '\'')
		state = 81;
	else if (c == '\"')
		state = 82;
	else if (is_metacharacter(c) || c == '\0')
		state = 83;
	else
		state = 80;
	return (state);
}

int		get_state_81(char c)
{
	int	state;

	if (c == '\0')
		state = -1;
	else if (c == '\'')
		state = 80;
	else if (c != '\'')
		state = 81;
	else
		state = -1;
	return (state);
}

int		get_state_82(char c)
{
	int	state;

	if (c == '\0')
		state = -1;
	else if (c == '\"')
		state = 80;
	else if (c != '\"')
		state = 82;
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