/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:12:53 by educastro         #+#    #+#             */
/*   Updated: 2024/09/04 16:00:14 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	init_values(int *i, t_aux_tree *aux_tree, t_token_list *token_list)
{
	*i = 0;
	aux_tree->pipe_idx = -1;
	aux_tree->aux = token_list;
	aux_tree->tree = NULL;
}

t_tree	*make_tree(t_token_list *token_list, t_minishell *data)
{
	t_aux_tree	aux_tree;

	init_values(&aux_tree.idx, &aux_tree, token_list);
	if (token_list == NULL)
		return (NULL);
	aux_tree.tree = ft_calloc(1, sizeof(t_tree));
	if (aux_tree.tree == NULL)
		return (NULL);
	if (aux_tree.pipe_idx != -1)
		aux_tree.idx = aux_tree.pipe_idx;
	else
	{
		free(aux_tree.tree);
		aux_tree.aux = ft_strdup(token_list); // precisa inverter
		aux_tree.tree = make_tree_cmd(); // para comandos simples
		token_clear_list(&aux_tree.aux);
		return (aux_tree.tree);
	}
	divide_tree(&aux_tree, token_list, data);
	return (aux_tree.tree);
}