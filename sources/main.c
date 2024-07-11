/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/07/11 19:10:40 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>

const char* get_token_type_name(t_token_type type) {  // APENAS PARA TESTES
    switch (type) {
        case WORD:         return "WORD";
        case QUOTE:        return "QUOTE";
        case DQUOTE:       return "DQUOTE";
        case BLOCK:        return "BLOCK";
        case ARCHIVE:      return "ARCHIVE";
        case PIPE:         return "PIPE";
        case HEREDOC:      return "HEREDOC";
        case REDIR_IN:     return "REDIR_IN";
        case REDIR_OUT:    return "REDIR_OUT";
        case REDIR_APPEND: return "REDIR_APPEND";
        case OR:           return "OR";
        case AND:          return "AND";
        case EXEC:         return "EXEC";
        default:           return "UNKNOWN";
    }
}

void	token_stack_fill(t_tok *token)
{
	token->prev = NULL;
	token->next = NULL;
	token->is_last = 0;
	token->type = 0;
}

void	parser(char *line)
{
	t_tok	*token;
	t_tok	*head;
	int		i;
	int		start;

	i = 0;
	token = malloc(sizeof(t_tok));
	head = token;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		start = i;
		if (line[i] == '|')
		{
			token->type = PIPE;
			token->data = NULL;
			token->is_last = 0;
			token->next = malloc(sizeof(t_tok));
			if (!token->next)
				break ; // FREEEEEEEEEEEEEEEEE
			token->next->prev = token;
			token = token->next;
			i++;
		}
		else if (line[i] == '>')
		{
			if (line[i + 1] == '>')
			{
				token->type = REDIR_APPEND;
				token->data = NULL;
				token->is_last = 0;
				token->next = malloc(sizeof(t_tok));
				if (!token->next)
					break ; // FREEEEEEEEEEEEEEEEE
				token->next->prev = token;
				token = token->next;
				i += 2;
			}
			else
			{
				token->type = REDIR_OUT;
				token->data = NULL;
				token->is_last = 0;
				token->next = malloc(sizeof(t_tok));
				if (!token->next)
					break ; // FREEEEEEEEEEEEEEEEE
				token->next->prev = token;
				token = token->next;
				i++;
			}
		}
		else if (line[i] == '<')
		{
			token->type = REDIR_IN;
			token->data = NULL;
			token->is_last = 0;
			token->next = malloc(sizeof(t_tok));
			if (!token->next)
				break ; // FREEEEEEEEEEEEEEEEE
			token->next->prev = token;
			token = token->next;
			i++;
		}
		else
		{
			while (line[i] && line[i] != ' ')
				i++;
			token->type = WORD;
			token->data = ft_substr(line, start, i - start);
			token->is_last = 0;
			token->next = malloc(sizeof(t_tok));
			if (!token->next)
				break ; // FREEEEEEEEEEEEEEEEE
			token->next->prev = token;
			token = token->next;
		}
	}
	token->is_last = 1;
	token->next = head;
	head->prev = token;
	token = head;
	while (token && !token->is_last)
	{
		printf("Data: %s.\t\tType: %s.\n", token->data, get_token_type_name(token->type));
		token = token->next;
	}
}

int	main(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		parser(line);
		printf("line: %s\n", line);
	}
	write(1, "Posto Shell\n", 13);
}