/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:15 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/08/23 19:03:09 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_syntax(t_token_list *tokens)
{
	t_token_list	*current;
	int	type;
	
	current = tokens;
	type = current->token.type;
	if (current->token.type == PIPE || current->token.type == REDIRECT_OUTPUT || current->token.type == REDIRECT_OUTPUT_APPEND )
	{
		printf("syntax error: unexpected operator at start of the line\n");
		return (FALSE);
	}
	while (current)
	{
		if ((current->token.type >= PIPE && current->token.type <= REDIRECT_HEREDOC) && current->next && current->next->token.type != WORD)
		{
			printf("syntax error: unexpected operator following another operator\n");
			return (FALSE);
		}
		if ((current->token.type >= PIPE && current->token.type <= REDIRECT_HEREDOC) && !current->next)
		{
			printf("syntax error: unexpected operator at end of the line\n");
			return (FALSE);
		}
		// {
		// 	printf("syntax error near unexpected token `|'\n");
		// 	return ;
		// }
		// if (type == PIPE && current->next->token.type == PIPE)
		// {
		// 	printf("syntax error near unexpected token `|'\n");
		// 	return ;
		// }
		// if (type == HERE_DOC && current->next == NULL)
		// {
		// 	printf("unexpected EOF while looking for matching `<<'\n");
		// 	return ;
		// }
		// if ()
		current = current->next;
	}
	return (TRUE);
}