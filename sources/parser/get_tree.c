/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:20:14 by educastro         #+#    #+#             */
/*   Updated: 2024/09/25 19:09:45 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tree	*get_tree(t_token_list *token_list, t_minishell *data)
{
	t_tree			*tree;
	t_token_list	*inverted_list;

	inverted_list = invert_list(token_get_sublist(token_list, 0, \
			token_list_size(token_list)));
	tree = make_tree(inverted_list, data);
	token_clear_list(&inverted_list);
	return (tree);
}

void	*free_tree(t_tree **tree)
{
	if (*tree == NULL)
		return (NULL);
	if ((*tree)->left)
		free_tree(&(*tree)->left);
	if ((*tree)->right)
		free_tree(&(*tree)->right);
	if ((*tree)->command)
		token_clear_list(&(*tree)->command);
	free(*tree);
	*tree = NULL;
	return (NULL);
}

void	*free_tree_all(t_tree **tree)
{
	if (*tree == NULL)
		return (NULL);
	if ((*tree)->left)
	{
		if ((*tree)->type == REDIRECT_HEREDOC)
			unlink((*tree)->left->command->token.lexeme);
		free_tree_all(&(*tree)->left);
	}
	if ((*tree)->right)
		free_tree_all(&(*tree)->right);
	if ((*tree)->command)
		token_clear_list(&(*tree)->command);
	free(*tree);
	*tree = NULL;
	return (NULL);
}
