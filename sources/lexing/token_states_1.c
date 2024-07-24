/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_states_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:11:55 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/24 17:00:09 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

int	get_state_1(char c)
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

int	get_state_40(char c)
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

int	get_state_50(char c)
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

int	get_state_60(char c)
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

int	get_state_70(char c)
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
