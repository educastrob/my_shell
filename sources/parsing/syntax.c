/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:15 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/08/22 18:19:57 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_syntax(t_token_list *tokens)
{
	t_token_list	*current;

	current = tokens;
	while (current)
	{
		if (current->token.type == PIPE && current->next == NULL)
		{
			printf("syntax error near unexpected token `|'\n");
			exit(1);
		}
		if (current->token.type == PIPE && current->next->token.type == PIPE)
		{
			printf("syntax error near unexpected token `|'\n");
			exit(1);
		}
		current = current->next;
	}
}