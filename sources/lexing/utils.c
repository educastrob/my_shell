/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:52:58 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/22 17:05:38 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

void	token_clear_list(t_token_list **token_list)
{
	t_token_list	*current;
	t_token_list	*next;

	current = *token_list;
	while (current)
	{
		next = current->next;
		free(current->token.lexeme);
		free(current);
		current = next;
	}
	*token_list = NULL;
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_metacharacter(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '\'' 
		|| c == '\"' || is_whitespace(c))
		return (1);
	return (0);
}
