/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:08:11 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/09 02:43:08 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/environment.h"

// retorna a estrutura env(name, value) pelo nome
t_env	*find_env(t_list *envs, char *name)
{
	t_env	*env;

	while (envs != NULL)
	{
		env = envs->content;
		if (ft_strncmp(env->name, name, ft_strlen(name) + 1) == 0)
			return (env);
		envs = envs->next;
	}
	return (NULL);
}

// retorna o valor do env pelo nome
char	*find_env_value(t_list *envs, char *name)
{
	t_env	*env;

	env = find_env(envs, name);
	if (env == NULL)
		return (NULL);
	return (env->value);
}

// retorna o node da lista de envs
t_list	*find_env_element(t_list *envs, char *name)
{
	t_env	*env;

	while (envs != NULL)
	{
		env = envs->content;
		if (ft_strncmp(env->name, name, ft_strlen(name) + 1) == 0)
			return (envs);
		envs = envs->next;
	}
	return (NULL);
}

// atualiza o caminho da variavel PWD
void	uptade_pwd_env(t_list *envs)
{
	char	*current_pwd;
	char	*old_pwd;

	current_pwd = getcwd(NULL, 0);
	old_pwd = find_env_value(envs, "PWD");
	update_env(envs, "OLDPWD", old_pwd);
	update_env(envs, "PWD", current_pwd);
	free(current_pwd);
}

enum e_bool	delete_env(t_minishell *minishell, char *name)
{
	t_list	*env;

	env = find_env_element(minishell->envs, name);
	if (env == NULL)
		return (FALSE);
	minishell->envs = ft_lstrm(minishell->envs, env, del_env);
	return (TRUE);
}
