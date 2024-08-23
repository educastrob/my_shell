/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:08:11 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/23 16:43:58 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	*free_env(t_env *env)
{
	free(env->name);
	free(env->value);
	free(env);
	env = NULL;
	return (env);
}

t_env	*init_env_update(char *name, char *value)
{
	t_env	*env;
	t_env	*new;

	env = *my_env(NULL);
	if (!(new = malloc(sizeof(t_env))))
		return (new);
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	if (env && !ft_strncmp(env->name, name, ft_strlen(name)))
	{
		new->next = env->next;
		free_env(env);
		env = new;
		return (NULL);
	}
	return (new);
}

int		update_env(char *name, char *value)
{
	t_env	*env;
	t_env	*new;

	env = *my_env(NULL);
	if (!(new = init_env_update(name, value)))
		return (0);
	while (env)
	{
		if (env->next && !ft_strncmp(env->next->name, name, ft_strlen(name)))
		{
			new->next = env->next->next;
			free_env(env->next);
			env->next = new;
			break ;
		}
		env = env->next;
	}
	if (env == NULL)
		free_env(new);
	return (0);
}