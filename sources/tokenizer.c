/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:39 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/18 19:08:46 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

static t_token_list	*token_create_node(char *lexeme, int token_type)
{
	t_token_list	*new_token;

	new_token = malloc(sizeof(t_token_list));
	new_token->token.lexeme = lexeme;
	new_token->token.type = token_type;
	new_token->next = NULL;
	return (new_token);
}

static void	add_token_to_list(t_token_list **token_list, char *lexeme, int token_type)
{
	t_token_list	*current;

	if (!*token_list)
	{
		*token_list = token_create_node(lexeme, token_type);
		return ;
	}
	current = *token_list;
	while (current->next)
		current = current->next;
	current->next = token_create_node(lexeme, token_type);
}

static void	token_clear_list(t_token_list **token_list)
{
	t_token_list	*current;
	t_token_list	*next;

	current = *token_list;
	while (current)
	{
		next = current->next;
		free(current->token.lexeme);
		free(current);
		current = next;
	}
	*token_list = NULL;
}

t_token_list	*get_token_list(char *str)
{
	t_token_list	*token_list;
	t_aux_token		aux;

	if (!str)
		return (NULL);
	ft_bzero(&aux, sizeof(t_aux_token));
	aux.state = 1;
	aux.str_length = ft_strlen(str);
	token_list = NULL;
	while (aux.i <= aux.str_length)
	{
		aux.token_type = get_token_type(aux.state);
		if (aux.state != 1)
			aux.lexeme_length += 1;
		if (aux.state == -1)
		{
			token_clear_list(&token_list);
			break ;
		}
		aux.i++;
	}
	return (token_list);
}