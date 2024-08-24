/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 05:11:02 by educastro         #+#    #+#             */
/*   Updated: 2024/08/24 17:05:30 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int		add_env(t_env **env, char *name, char *value)
{
	t_env	*new;
	t_env	*tmp;

	tmp = *env;
	if (get_env(env, name))
	{
		actualise_env(env, name, value);
		return (0);
	}
	if (!(new = malloc(sizeof(t_env))))
		return (1);
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	new->next = NULL;
	if (env == NULL)
	{
		env = &new;
		return (0);
	}
	while (tmp->next != NULL)
		env = &tmp->next;
	tmp->next = new;
	return (0);
}

int		init_env(t_env **env, char *envp[])
{
	char	*value;
	char	*name;
	int		i;
	int		j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		name = ft_substr(envp[i], 0, j);
		value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]));
		add_env(env, name, value);
		free(name);
		free(value);
		i++;
	}
	add_env(env, "PIPESTATUS", "0");
	return (0);
}

t_env	*get_env(t_env **env, char *name)
{
	t_env *tmp;

	tmp = *env;
	if (!name || !tmp)
		return (NULL);
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, name, ft_strlen(name)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*get_env_value(t_env **env, char *name)
{
	t_env *tmp;

	tmp = *env;
	if (!name || !tmp || !name[0])
		return (NULL);
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, name, ft_strlen(name)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	*free_all_env(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (env)
	{
		free((*env)->name);
		free((*env)->value);
		tmp = (*env)->next;
		free(env);
		env = &tmp;
	}
	return (env);
}
