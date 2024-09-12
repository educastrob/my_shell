/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:13:14 by edcastro          #+#    #+#             */
/*   Updated: 2024/09/12 14:49:43 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

const char *get_token_type_string(enum e_token_type type)
{
    switch (type)
    {
        case WORD: return "WORD";
        case PIPE: return "PIPE";
        case REDIRECT_INPUT: return "REDIRECT_INPUT";
        case REDIRECT_HEREDOC: return "REDIRECT_HEREDOC";
        case REDIRECT_OUTPUT: return "REDIRECT_OUTPUT";
        case REDIRECT_OUTPUT_APPEND: return "REDIRECT_OUTPUT_APPEND";
        case EXPRESSION: return "EXPRESSION";
        case COMMAND: return "COMMAND";
        default: return "UNKNOWN";
    }
}

void print_token_list(t_token_list *token_list)
{
    t_token_list *current = token_list;
    while (current)
    {
        printf("lexeme: %s, type: %s\n", current->token.lexeme, get_token_type_string(current->token.type));
        current = current->next;
    }
}
