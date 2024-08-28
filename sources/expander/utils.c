/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:37 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/28 13:08:01 by edcastro         ###   ########.fr       */
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
			ft_printf("%s=%s\n", env->name, env->value);
		envs = envs->next;
	}
	return (EXIT_SUCCESS);
}
