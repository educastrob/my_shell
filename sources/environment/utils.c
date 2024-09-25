/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:37 by edcastro          #+#    #+#             */
/*   Updated: 2024/09/25 16:19:21 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/environment.h"

static void	create_pwd_env(t_minishell *minishell);

// inicializa o environment
t_minishell     *init_minishell(char **envp)
{
    t_minishell *minishell;

    minishell = ft_calloc(1, sizeof(t_minishell));
    minishell->envs = create_envs(envp);
	create_pwd_env(minishell);
    return (minishell);
}

// caso não exista, cria a variável pwd no env
static void	create_pwd_env(t_minishell *minishell)
{
	char	*current_pwd;
	t_env	*pwd_env;

	current_pwd = getcwd(NULL, 0);
	pwd_env = find_env(minishell->envs, "PWD");
	if (pwd_env == NULL)
		add_env(minishell->envs, "PWD", current_pwd);
	pwd_env = find_env(minishell->envs, "OLDPWD");
	if (pwd_env == NULL)
		add_env(minishell->envs, "OLDPWD", current_pwd);
	free(current_pwd);
}
