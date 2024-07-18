/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:39 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/18 16:20:24 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexing.h"

static t_token_list	*token_create_node(char *lexeme, int token_type)
{
	t_token_list	*new_token;

	new_token = malloc(sizeof(t_token_list));
	new_token->token.lexeme = lexeme;
	new_token->token.type = token_type;
	new_token->next = NULL;
	return (new_token);
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
		aux.state = token_get_next_state(aux.state, str[aux.i]);
		if (aux.state != 1)
			aux.lexeme_length += 1;
		if (aux.state == -1)
		{
			token_clear_list(&token_list);
			break ;
		}
		if (token_state_is_final(aux.state))
			aux_token_state_final(&aux, str, &token_list);
		aux.i++;
	}
	return (token_list);
}