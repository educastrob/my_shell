/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:43:55 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/29 17:46:19 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env(t_minishell *minishell)
{
	t_list	*envs;
	t_env	*env;

	envs = minishell->envs;
	while (envs != NULL)
	{
		env = envs->content;
		if (env->value != NULL)
			printf("%s=%s\n", env->name, env->value);
		envs = envs->next;
	}
	return (EXIT_SUCCESS);
}
