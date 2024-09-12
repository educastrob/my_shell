/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:12:53 by educastro         #+#    #+#             */
/*   Updated: 2024/09/12 18:11:45 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static void		divide_tree(t_aux_tree *aux_tree, t_token_list *token_list, t_minishell *data)
{
	aux_tree->aux = token_get_node_index(token_list, aux_tree->idx);
	if (aux_tree->aux)
		aux_tree->tree->type = aux_tree->aux->token.type;
	aux_tree->sublist_left = token_get_sublist(token_list, 0, aux_tree->idx);
	aux_tree->sublist_right = token_get_sublist(token_list, aux_tree->idx + 1, token_list_size(token_list));
	aux_tree->tree->left = make_tree(aux_tree->sublist_right, data);
	if (aux_tree->tree->left)
		aux_tree->tree->right = make_tree(aux_tree->sublist_left, data);
	token_clear_list(&aux_tree->sublist_left);
	token_clear_list(&aux_tree->sublist_right);
	if (aux_tree->tree->left == NULL || aux_tree->tree->right == NULL)
		free_tree(&aux_tree->tree);
}

static void		find_division_pipe_index(t_aux_tree *aux_tree)
{
	while (aux_tree)
	{
		if (aux_tree->pipe_idx == -1 && (aux_tree->aux->token.type == PIPE))
			aux_tree->pipe_idx = aux_tree->idx;
		aux_tree->idx++;
		if (aux_tree->aux)
			aux_tree->aux = aux_tree->aux->next;
	}
}

static void		init_values(int *i, t_aux_tree *aux_tree, t_token_list *token_list)
{
	*i = 0;
	aux_tree->pipe_idx = -1;
	aux_tree->aux = token_list;
	aux_tree->tree = NULL;
}

t_tree			*make_tree(t_token_list *token_list, t_minishell *data)
{
	t_aux_tree	aux_tree;

	init_values(&aux_tree.idx, &aux_tree, token_list);
	if (token_list == NULL)
		return (NULL);
	aux_tree.tree = ft_calloc(1, sizeof(t_tree));
	find_division_pipe_index(&aux_tree);
	if (aux_tree.tree == NULL)
		return (NULL);
	if (aux_tree.pipe_idx != -1)
		aux_tree.idx = aux_tree.pipe_idx;
	else
	{
		free(aux_tree.tree);
		aux_tree.aux = invert_list(token_list); // precisa inverter
		aux_tree.tree = make_tree_cmd(); // para comandos simples
		token_clear_list(&aux_tree.aux);
		return (aux_tree.tree);
	}
	divide_tree(&aux_tree, token_list, data);
	return (aux_tree.tree);
}