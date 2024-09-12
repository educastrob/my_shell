/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:20:14 by educastro         #+#    #+#             */
/*   Updated: 2024/09/12 18:06:04 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tree	*get_tree(t_token_list *token_list, t_minishell *data)
{
	t_tree			*tree;
	t_token_list	*inverted_list = ft_strdup(token_list);

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
