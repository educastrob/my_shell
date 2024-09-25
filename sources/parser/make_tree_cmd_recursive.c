/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_cmd_recursive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:21:23 by educastro         #+#    #+#             */
/*   Updated: 2024/09/23 22:21:15 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_tree		*make_tree_cmd_recursive(t_token_list *redir_list, t_token_list *args, t_minishell *data)
{
	t_tree	*tree;

	tree = ft_calloc(0, sizeof(t_tree));
	if (!redir_list)
	{
		tree->type = COMMAND;
		tree->command = token_get_sublist(args, 0, token_list_size(args));
	}
	else if (redir_list && redir_list->token.type != WORD && redir_list->next && redir_list->next->token.type == WORD)
		make_redirects(); // a fazer
	else
		free_tree(&tree);
	return (tree);
}
