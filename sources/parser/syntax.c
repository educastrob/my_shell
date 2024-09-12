/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:52:47 by edcastro          #+#    #+#             */
/*   Updated: 2024/09/12 14:40:43 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*check_syntax(t_token_list *tokens)
{
	t_token_list	*current;
	
	current = tokens;
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
