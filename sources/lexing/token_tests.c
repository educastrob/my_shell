/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:13:14 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/23 18:44:22 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char *get_token_type_string(enum e_token type)
{
    switch (type)
    {
        case WORD: return "WORD";
        case PIPE: return "PIPE";
        case REDIRECT_INPUT: return "REDIRECT_INPUT";
        case REDIRECT_HEREDOC: return "REDIRECT_HEREDOC";
        case REDIRECT_OUTPUT: return "REDIRECT_OUTPUT";
        case REDIRECT_OUTPUT_APPEND: return "REDIRECT_OUTPUT_APPEND";
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
