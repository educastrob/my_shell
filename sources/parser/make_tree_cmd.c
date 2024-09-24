/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:21:04 by edcastro          #+#    #+#             */
/*   Updated: 2024/09/24 14:41:21 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static void	init_values(t_aux_tree *aux_tree, t_token_list *token_list)
{
	ft_bzero(aux_tree, sizeof(t_aux_tree));
	aux_tree->aux = token_list;
}

static void	put_redirect_on_list(t_aux_tree *aux_tree)
{
	token_add_to_list(&aux_tree->redir_list, aux_tree->aux);
	if (aux_tree->aux->next)
	{
		token_add_to_list(&aux_tree->redir_list, \
			ft_strdup(aux_tree->aux->next->token.lexeme, \
			aux_tree->aux->next->token.type));
		aux_tree->aux = aux_tree->aux->next;
	}
}

t_tree	*make_tree_cmd(t_token *token_list, t_minishell *data)
{
	t_aux_tree	*aux_tree;
	
	init_values(&aux_tree, token_list);
	while (aux_tree.aux)
	{
		if (aux_tree.aux->type >= REDIRECT_INPUT
			&& aux_tree.aux->type <= REDIRECT_OUTPUT_APPEND)
			put_redirect_on_list(&aux_tree);
		else
			token_add_to_list(&aux_tree.args, \
			ft_strdup(aux_tree.aux->token.lexeme, \
			aux_tree.aux->token.type));
		aux_tree.aux = aux_tree.aux->next;
		
	}
	token_clear_list(&aux_tree.args);
	token_clear_list(&aux_tree.redir_list);
	return (aux_tree.tree);
}