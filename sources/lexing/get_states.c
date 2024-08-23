/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:44:40 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/23 18:44:36 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_token_type(int state)
{
	int	type;

	if (state == 40)
		type = PIPE;
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

int		token_state_requires_backtrack(int state)
{
	if (state == 62
		|| state == 72
		|| state == 83)
		return (1);
	return (0);
}

int		token_state_is_final(int state)
{
	if ( state == 40 
		|| state == 61
		|| state == 62
		|| state == 71
		|| state == 72
		|| state == 83)
		return (1);
	return (0);
}

int		token_get_next_state(int state, char c)
{
	int	next_state;

	if (state == 1)
		next_state = get_state_1(c);
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
