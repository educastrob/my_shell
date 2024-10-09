/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:52:18 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/10/09 17:24:24 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"
#include "../../includes/environment.h"
#include "../../includes/executor.h"

int	key_exist(char *key, t_list *envp_list)
{
	t_list	*tmp;
	t_env	*env;

	tmp = envp_list;
	while (tmp)
	{
		env = (t_env *)tmp->content;  // Acessa o conteúdo da lista como um t_env
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

void	print_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "?", -1) == 0)
			continue ;
		printf("declare -x %s\n", envp[i]);
		i++;
	}
}

void	print_sorted_envp(t_minishell *data)
{
	int		i;
	int		j;
	char	*temp;
	char	**envp;

	envp = create_envs(data->envs);
	i = 0;
	while (envp[i])
	{
		j = i + 1;
		while (envp[j])
		{
			if (ft_strncmp(envp[i], envp[j], -1) > 0)
			{
				temp = envp[i];
				envp[i] = envp[j];
				envp[j] = temp;
			}
			j++;
		}
		i++;
	}
	print_envp(envp);
	free_envp(envp);
}
