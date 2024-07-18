/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:39 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/16 19:50:47 by edcastro         ###   ########.fr       */
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

static int	get_lexeme_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

void	tokenizer(char *line)
{
	t_token_list	*token_list;
	t_token_list	*current_token;
	t_aux_token		aux;

	token_list = NULL;
	current_token = NULL;
	aux.i = 0;
	aux.lexeme_length = 0;
	aux.str_length = ft_strlen(line);
	while (aux.i < aux.str_length)
	{
		if (line[aux.i] == ' ')
			aux.i++;
		else
		{
			aux.lexeme_length = get_lexeme_length(line + aux.i);
			if (current_token == NULL)
			{
				current_token = token_create_node(ft_substr(line, aux.i, aux.lexeme_length), get_token_type(get_state(line + aux.i)));
				token_list = current_token;
			}
			else
			{
				current_token->next = token_create_node(ft_substr(line, aux.i, aux.lexeme_length), get_token_type(get_state(line + aux.i)));
				current_token = current_token->next;
			}
			aux.i += aux.lexeme_length;
		}
	}
	while (token_list)
	{
		printf("lexeme: %s, type: %d\n", token_list->token.lexeme, token_list->token.type);
		token_list = token_list->next;
	}
}