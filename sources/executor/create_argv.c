/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:06:17 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/17 23:50:35 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token_list	*get_command_list(t_token_list *token_list)
{
	char			*expanded_string;
	t_token_list	*aux;
	t_token_list	*expanded_list;

	aux = token_list;
	expanded_list = NULL;
	while (aux)
	{
		expanded_string = aux->token.lexeme;
		if (ft_strlen(expanded_string) != 0)
			add_token_to_list(&expanded_list, ft_strdup(expanded_string), WORD);
		free(expanded_string);
		aux = aux->next;
	}
	return (expanded_list);
}

char	**create_argv(t_tree *tree, t_minishell *data)
{
	int				i;
	int				args_num;
	char			**argv;
	t_token_list	*command_list;

	i = 0;
	command_list = get_command_list(tree->command);
	args_num = token_list_size(command_list);
	argv = malloc((args_num + 1) * sizeof(char *));
	argv[args_num] = NULL;
	while (i < args_num)
	{
		argv[i] = expand_string(token_get_node_index(\
			command_list, i)->token.lexeme, data->envs);
		i++;
	}
	token_clear_list(&command_list);
	return (argv);
}
