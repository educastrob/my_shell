/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_states_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:19:51 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/23 18:44:30 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_state_80(char c)
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

int	get_state_81(char c)
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

int	get_state_82(char c)
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
