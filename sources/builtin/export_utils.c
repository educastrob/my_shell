/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:52:18 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/10/10 01:28:11 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"
#include "../../includes/environment.h"
#include "../../includes/executor.h"

int	key_is_valid(char *key)
{
	int	i;

	i = 0;
	if (ft_isdigit(key[0]))
		return (0);
	while (key[i] && (ft_isalnum(key[i]) || key[i] == '_'))
		i++;
	if (key[i] == '\0')
		return (1);
	return (0);
}

int	key_exist(char *key, t_list *envp_list)
{
	t_list	*tmp;
	t_env	*env;

	tmp = envp_list;
	while (tmp)
	{
		env = (t_env *)tmp->content;
		if (ft_strncmp(env->name, key, -1) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}


void	export_perror(char *key_value)
{
	int			length;
	char		*message_to_print;
	const char	*message[2] = {"ERROR: export: '", \
								"': not a valid identifier"};

	length = ft_strlen(message[0]) + ft_strlen(key_value) \
						+ ft_strlen(message[1]) + 1;
	message_to_print = malloc(length);
	ft_strlcpy(message_to_print, message[0], length);
	ft_strlcat(message_to_print, key_value, length);
	ft_strlcat(message_to_print, message[1], length);
	ft_putendl_fd(message_to_print, STDERR_FILENO);
	free(message_to_print);
}

static char	*create_env_string(t_env *env)
{
	int		full_size;
	char	*env_string;

	full_size = ft_strlen(env->name) + ft_strlen(env->value) + 2;
	env_string = malloc(sizeof(char) * full_size);
	ft_strlcpy(env_string, env->name, full_size);
	if (env->value)
	{
		ft_strlcat(env_string, "=", full_size);
		ft_strlcat(env_string, env->value, full_size);
	}
	return (env_string);
}

char	**populate_envs(t_list *head)
{
	int		i;
	char	**new_envp;
	t_list	*temp;
	t_env	*env;

	i = 0;
	temp = head;
	new_envp = ft_calloc(sizeof(char *), envp_list_size(head));
	while (temp)
	{
		env = (t_env *)temp->content;
		if (ft_strncmp(env->name, "?", -1) != 0)
		{
			new_envp[i] = create_env_string(env);
			i++;
		}
		temp = temp->next;
	}
	return (new_envp);
}

