/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_cmd_recursive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:21:23 by educastro         #+#    #+#             */
/*   Updated: 2024/09/24 14:09:56 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static void	make_redirects(t_tree *tree, t_token_list *redir_list, t_minishell *data, t_token_list *args)
{
	char	*str;

	(*tree)->type = redir_list->token.type;
	(*tree)->left = ft_calloc(1, sizeof(t_tree));
	(*tree)->left->type = COMMAND;
	if ((*tree)->type == REDIRECT_HEREDOC)
	{
		str = create_here_doc(); // precisa criar
		(*tree)->left->command = get_token_list(str);
		free(str);
	}
	else
		(*tree)->left->command = token_get_sublist(redir_list, 1, 1);
	if ((*tree)->left->command)
		(*tree)->right = make_tree_cmd_recursive(\
			token_get_node_index(redir_list, 2), args, data);
	if (!(*tree)->right || !(*tree)->left->command)
		free_tree(tree);
}

t_tree		*make_tree_cmd_recursive(t_token_list *redir_list, t_token_list *args, t_minishell *data)
{
	t_tree	*tree;

	tree = ft_calloc(1, sizeof(t_tree));
	if (!redir_list)
	{
		tree->type = COMMAND;
		tree->command = token_get_sublist(args, 0, token_list_size(args));
	}
	else if (redir_list && redir_list->token.type != WORD && redir_list->next && redir_list->next->token.type == WORD)
		make_redirects(&tree, redir_list, data, args);
	else
		free_tree(&tree);
	return (tree);
}
