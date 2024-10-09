/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:43:44 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/09 17:49:38 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

// add redirects em redir_list
static void	put_redirect_on_list(t_aux_tree *aux_tree)
{
	add_token_to_list(&aux_tree->redir_list, NULL, aux_tree->aux->token.type);

	if (aux_tree->aux->next)
	{
		add_token_to_list(&aux_tree->redir_list, 
			ft_strdup(aux_tree->aux->next->token.lexeme), 
			aux_tree->aux->next->token.type);

		aux_tree->aux = aux_tree->aux->next;
	}
}

// processa redirects e constrói a árvore
static void	make_redirects(t_tree **tree, t_token_list *redir_list, t_token_list *args, t_minishell *data)
{
	char	*str;

	(*tree)->type = redir_list->token.type;
	(*tree)->left = ft_calloc(1, sizeof(t_tree));
	(*tree)->left->type = COMMAND;
	if ((*tree)->type == REDIRECT_HEREDOC)
	{
		str = create_heredoc(redir_list->next->token.lexeme, data); // cria o HEREDOC
		(*tree)->left->command = get_token_list(str); // obtem lista de tokens do HEREDOC
		free(str);
	}
	else
		(*tree)->left->command = token_get_sublist(args, 0, token_list_size(args));
	// processa próximo redirect, se houver aloca memória para a subárvore direita
	if (redir_list->next && redir_list->next->next)
		(*tree)->right = ft_calloc(1, sizeof(t_tree));
	else
		(*tree)->right = NULL;
	if (!(*tree)->left->command)
		free_tree(tree);
}

static void	init_values(t_aux_tree *aux_tree, t_token_list *token_list)
{
	ft_bzero(aux_tree, sizeof(t_aux_tree));
	aux_tree->aux = token_list;
}

// cria a árvore de execução de comandos
t_tree	*make_tree_cmd(t_token_list *token_list, t_minishell *data)
{
	t_aux_tree	aux_tree;
	t_tree		*tree;

	init_values(&aux_tree, token_list);
	while (aux_tree.aux)
	{
		if (aux_tree.aux->token.type >= REDIRECT_INPUT
			&& aux_tree.aux->token.type <= REDIRECT_OUTPUT_APPEND)
			put_redirect_on_list(&aux_tree);
		else
		{
			add_token_to_list(&aux_tree.args, 
				ft_strdup(aux_tree.aux->token.lexeme), 
				aux_tree.aux->token.type);
		}
		aux_tree.aux = aux_tree.aux->next;
	}
	tree = ft_calloc(1, sizeof(t_tree));
	if (!aux_tree.redir_list)
	{
		tree->type = COMMAND;
		tree->command = token_get_sublist(aux_tree.args, 0, token_list_size(aux_tree.args));
	}
	else
		make_redirects(&tree, aux_tree.redir_list, aux_tree.args, data);
	token_clear_list(&aux_tree.args);
	token_clear_list(&aux_tree.redir_list);
	return (tree);
}
