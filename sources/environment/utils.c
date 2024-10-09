/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:37 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/09 03:02:10 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/environment.h"

// inicializa o environment
// t_minishell     *init_minishell(char **envp)
// {
//     t_minishell *minishell;

//     minishell = ft_calloc(1, sizeof(t_minishell));
//     minishell->envs = create_envs(envp);
// 	create_pwd_env(minishell);
//     return (minishell);
// }

// caso não exista, cria a variável pwd no env
// void	uptade_pwd_env(t_list *envs)
// {
// 	char	*current_pwd;
// 	char	*old_pwd;

// 	current_pwd = getcwd(NULL, 0);
// 	old_pwd = find_env_value(envs, "PWD");
// 	update_env(envs, "OLDPWD", old_pwd);
// 	update_env(envs, "PWD", current_pwd);
// 	free(current_pwd);
// }

void	del_env(void *content)
{
	t_env	*env;

	env = content;
	free(env->name);
	free(env->value);
	free(env);
}
