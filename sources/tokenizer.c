/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:39 by edcastro          #+#    #+#             */
/*   Updated: 2024/07/23 18:10:44 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

static const char *get_token_type_string(enum e_token type)
{
    switch (type)
    {
        case WORD: return "WORD";
        case PIPE: return "PIPE";
        case REDIRECT_INPUT: return "REDIRECT_INPUT";
        case REDIRECT_HEREDOC: return "REDIRECT_HEREDOC";
        case REDIRECT_OUTPUT: return "REDIRECT_OUTPUT";
        case REDIRECT_OUTPUT_APPEND: return "REDIRECT_OUTPUT_APPEND";
        case OR: return "OR";
        case AND: return "AND";
        case OPEN_PARENTHESIS: return "OPEN_PARENTHESIS";
        case CLOSE_PARENTHESIS: return "CLOSE_PARENTHESIS";
        case EXPRESSION: return "EXPRESSION";
        case COMMAND: return "COMMAND";
        case SUBSHELL: return "SUBSHELL";
        default: return "UNKNOWN";
    }
}

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

t_token_list	*token_get_sublist(t_token_list *token_lst, int start, int lst_len)
{
	int	i;
	t_token_list	*sublist;
	t_token_list	*aux;

	i = 0;
	sublist = NULL;
	aux = token_lst;
	while (aux && i < start)
	{
		aux = aux->next;
		i++;
	}
	i = 0;
	while (aux && i < lst_len)
	{
		add_token_to_list(&sublist, ft_strdup(aux->token.lexeme), aux->token.type);
		aux = aux->next;
		i++;
	}
	return (sublist);
}

void	token_final_state(t_aux_token *aux, t_token_list **token_list, char *str)
{
	if (token_state_requires_backtrack(aux->state))
	{
		aux->i -= 1;
		aux->lexeme_length -= 1;
	}
	aux->token_type = get_token_type(aux->state);
	if (aux->token_type == WORD)
		aux->lexeme = ft_substr(str, aux->i - (aux->lexeme_length - 1), \
		aux->lexeme_length);
	else
		aux->lexeme = NULL;
	add_token_to_list(token_list, aux->lexeme, aux->token_type);
	aux->lexeme_length = 0;
	aux->state = 1;	
}

static void print_token_list(t_token_list *token_list) 
{
    t_token_list *current = token_list;
    while (current)
    {
        printf("lexeme: %s, type: %s\n", current->token.lexeme, get_token_type_string(current->token.type));
        current = current->next;
    }
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
			token_final_state(&aux, &token_list, str);
		aux.i++;
	}
	printf("1o token: %s\n", token_list->token.lexeme); // ============ TEST
	print_token_list(token_list); // ============ TEST
	return (token_list);
}
