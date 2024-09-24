/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:43:44 by edcastro          #+#    #+#             */
/*   Updated: 2024/09/24 15:49:15 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

// Função que adiciona redirecionamentos à lista
static void	put_redirect_on_list(t_aux_tree *aux_tree)
{
	token_add_to_list(&aux_tree->redir_list, NULL, aux_tree->aux->token.type);

	if (aux_tree->aux->next)
	{
		token_add_to_list(&aux_tree->redir_list, 
			ft_strdup(aux_tree->aux->next->token.lexeme), 
			aux_tree->aux->next->token.type);

		aux_tree->aux = aux_tree->aux->next;
	}
}

// Função para processar redirecionamentos e construir a árvore
static void	make_redirects(t_tree **tree, t_token_list *redir_list, t_token_list *args, t_minishell *data)
{
	char	*str;

	(*tree)->type = redir_list->token.type;
	(*tree)->left = ft_calloc(1, sizeof(t_tree));
	(*tree)->left->type = COMMAND;

	// Tratamento para HEREDOC
	if ((*tree)->type == REDIRECT_HEREDOC)
	{
		str = create_here_doc(redir_list->next->token.lexeme, data); // Função para criar o HEREDOC (você deve implementar)
		(*tree)->left->command = get_token_list(str); // Obtém a lista de tokens do HEREDOC
		free(str);
	}
	else
	{
		// Obtém a sublista de argumentos para o comando
		(*tree)->left->command = token_get_sublist(args, 0, token_list_size(args));
	}

	// Processa o próximo redirecionamento, se houver
	if (redir_list->next && redir_list->next->next)
		(*tree)->right = ft_calloc(1, sizeof(t_tree)); // Aloca o próximo nó
	else
		(*tree)->right = NULL;

	// Se não houver comandos ou a árvore estiver incompleta, libera
	if (!(*tree)->left->command)
		free_tree(tree);
}

static void	init_values(t_aux_tree *aux_tree, t_token_list *token_list)
{
	ft_bzero(aux_tree, sizeof(t_aux_tree));
	aux_tree->aux = token_list;
}

// Função principal que cria a árvore de execução de comandos
t_tree	*make_tree_cmd(t_token_list *token_list, t_minishell *data)
{
	t_aux_tree	aux_tree;
	t_tree		*tree;

	init_values(&aux_tree, token_list); // Inicializa os valores

	// Percorre a lista de tokens
	while (aux_tree.aux)
	{
		// Identifica redirecionamentos
		if (aux_tree.aux->token.type >= REDIRECT_INPUT
			&& aux_tree.aux->token.type <= REDIRECT_OUTPUT_APPEND)
		{
			put_redirect_on_list(&aux_tree); // Adiciona à lista de redirecionamentos
		}
		else
		{
			// Caso contrário, adiciona à lista de argumentos
			token_add_to_list(&aux_tree.args, 
				ft_strdup(aux_tree.aux->token.lexeme), 
				aux_tree.aux->token.type);
		}

		aux_tree.aux = aux_tree.aux->next; // Avança para o próximo token
	}

	// Cria a árvore principal de comandos e redirecionamentos
	tree = ft_calloc(1, sizeof(t_tree));
	if (!aux_tree.redir_list)  // Se não houver redirecionamentos, cria um comando simples
	{
		tree->type = COMMAND;
		tree->command = token_get_sublist(aux_tree.args, 0, token_list_size(aux_tree.args));
	}
	else
	{
		// Se houver redirecionamentos, cria a árvore com tratamento adequado
		make_redirects(&tree, aux_tree.redir_list, aux_tree.args, data);
	}

	// Limpa as listas temporárias
	token_clear_list(&aux_tree.args);
	token_clear_list(&aux_tree.redir_list);

	return (tree); // Retorna a árvore de execução
}
