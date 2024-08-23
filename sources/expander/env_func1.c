/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 05:11:02 by educastro         #+#    #+#             */
/*   Updated: 2024/08/23 16:51:16 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

// cria os nodes na lista encadeada.
int		add_env(char *name, char *value)
{
	t_env	*new_node;
	t_env	*env;

	env = *my_env(NULL);
	if (get_env(name))
	{
		update_env(name, value);
		return (0);
	}
	if (!(new_node = malloc(sizeof(t_env))))
		return (1);
	new_node->name = ft_strdup(name);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	if (env == NULL)
		env = new_node;
	else
	{
		while (env->next != NULL)
			env = env->next;
		env->next = new_node;
	}
	return (0);
}

// percorre o env e retorna todas as variaveis de ambiente alocadas.
int		init_env(char **envp)
{
	t_env	*env;
	char	*name;
	char	*value;
	int		i;
	int		j;

	env = *my_env(NULL);
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		name = ft_substr(envp[i], 0, j);
		value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]));
		add_env(name, value);
		free(name);
		free(value);
		i++;
	}
	add_env("PIPESTATUS", "0");
	return (0);
}

// retorna o link da lista cujo nome é igual ao passado no parâmetro.
t_env	*get_env(char *name)
{
	t_env	*env;

	env = *my_env(NULL);
	if (!name || !env || !name[0])
		return (NULL);
	while (env)
	{
		if (!(ft_strncmp(env->name, name, ft_strlen(name))))
			return (env);
		env = env->next;
	}
	return (NULL);
}

// retorna o valor (como uma string) da variável de ambiente correspondente ao nome passado como parâmetro se uma correspondência for encontrada, ou um ponteiro nulo se nenhuma variável de ambiente for encontrada.
char	*get_env_value(char *name)
{
	t_env	*env;

	env = *my_env(NULL);
	if (!name || !env || !name[0])
		return (NULL);
	while (env)
	{
		if (!(ft_strncmp(env->name, name, ft_strlen(name))))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

// free all
void	*free_all_env(void)
{
	t_env	*tmp;
	t_env	*env;

	env = *my_env(NULL);
	while (env)
	{
		free(env->name);
		free(env->value);
		tmp = env->next;
		free(env);
		env = tmp;
	}
	return (env);
}
