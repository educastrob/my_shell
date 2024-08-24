/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:08:11 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/24 16:15:04 by edcastro         ###   ########.fr       */
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

t_env	*init_actualise(t_env *env, char *name, char *value)
{
	t_env *new;

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

int		actualise_env(t_env **env, char *name, char *value)
{
	t_env	*ret;
	t_env	*new;

	ret = *env;
	if (!(new = init_actualise(*env, name, value)))
		return (0);
	while (env)
	{
		if ((*env)->next && !ft_strncmp((*env)->next->name, name,
			ft_strlen(name)))
		{
			new->next = (*env)->next->next;
			free_env((*env)->next);
			(*env)->next = new;
			break ;
		}
		env = &(*env)->next;
	}
	if (*env == NULL)
		free_env(new);
	*env = ret;
	return (0);
}