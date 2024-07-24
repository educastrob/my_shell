/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:52:58 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/24 17:00:55 by edcastro         ###   ########.fr       */
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
	if (c == '|' || c == '<' || c == '>' || c == '&' || c == '\'' 
		|| c == '\"' || c == '(' || c == ')' || is_whitespace(c))
		return (1);
	return (0);
}
