/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:57:41 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/09/04 21:12:44 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	command_list_size(t_token_list *token_list)
{
	size_t	size;
	t_token_list	*tmp;

	size = 0;
	tmp = token_list;
	while (tmp->next && tmp->token.type == WORD)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

char	**command_args(t_token_list *token_list)
{
	char	**args;
	t_token_list	*tmp;
	size_t	size;
	size_t	i;

	size = command_list_size(token_list);
	args = malloc(sizeof(char *) * (size + 1));
	if (!args)
		return (NULL);
	tmp = token_list;
	i = 0;
	while (tmp->next && tmp->token.type == WORD)
	{
		args[i] = ft_strdup(tmp->token.lexeme);
		if (!args[i])
		{
			while (i > 0)
				free(args[i--]);
			free(args);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

