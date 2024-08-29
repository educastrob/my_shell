/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:15 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/08/29 16:32:57 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_syntax(t_token_list *tokens)
{
	t_token_list	*current;
	int	type;
	
	current = tokens;
	type = current->token.type;
	if (current->token.type == PIPE)
		return ("syntax error: unexpected operator at start of the line\n");
	while (current)
	{
		if ((current->token.type >= PIPE && current->token.type <= REDIRECT_HEREDOC) && current->next && current->next->token.type != WORD)
			return ("syntax error: unexpected operator following another operator\n");
		if ((current->token.type >= PIPE && current->token.type <= REDIRECT_HEREDOC) && !current->next)
			return ("syntax error: unexpected operator at end of the line\n");
		current = current->next;
	}
	return (0);
}
