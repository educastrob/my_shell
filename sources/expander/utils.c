/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:37 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/28 15:11:53 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"

// inicializa o envp
t_minishell     *init_minishell(char **envp)
{
    t_minishell *minishell;

    minishell = ft_calloc(1, sizeof(t_minishell));
    minishell->envs = create_envs(envp);
    return (minishell);
}

int	print_env(t_minishell *minishell)
{
	t_list	*envs;
	t_env	*env;

	envs = minishell->envs;
	while (envs != NULL)
	{
		env = envs->content;
		if (env->value != NULL)
			printf("%s=%s   ----->   Adicionado ao endereço: %p\n", env->name, env->value, envs->content);
		envs = envs->next;
	}
	return (EXIT_SUCCESS);
}
