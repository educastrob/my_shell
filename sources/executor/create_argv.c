/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:06:17 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/09 17:49:01 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token_list	*get_expanded_list(t_token_list *token_list, t_list *envp)
{
	char			*expanded_string;
	t_token_list	*aux;
	t_token_list	*expanded_list;

	aux = token_list;
	expanded_list = NULL;
	while (aux)
	{
		expanded_string = expand_string(aux->token.lexeme, envp);
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
	t_token_list	*expanded_list;

	i = 0;
	expanded_list = get_expanded_list(tree->command, data->envs);
	args_num = token_list_size(expanded_list);
	argv = malloc((args_num + 1) * sizeof(char *));
	argv[args_num] = NULL;
	while (i < args_num)
	{
		argv[i] = expand_string(token_get_node_index(\
			expanded_list, i)->token.lexeme, data->envs);
		i++;
	}
	token_clear_list(&expanded_list);
	return (argv);
}
