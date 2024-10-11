/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:35:20 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/10/10 01:19:53 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"
#include "../../includes/environment.h"
#include "../../includes/executor.h"

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

	envp = populate_envs(data->envs);
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

int	set_arg(char *arg, int idx, t_list *envp_list)
{
	int		ret_code;
	char	*key;
	char	*value;

	ret_code = 0;
	key = ft_substr(arg, 0, idx);
	value = ft_substr(arg, idx + 1, ft_strlen(arg) - idx);
	if (key && key[0] && value && key_is_valid(key))
	{
		if (key_exist(key, envp_list))
			update_env(envp_list, key, value);
		else
			add_env(envp_list, key, value);
	}
	else
	{
		export_perror(arg);
		ret_code = 1;
	}
	free(key);
	free(value);
	return (ret_code);
}

int	select_arg(char *arg, t_minishell *data)
{
	int	i;
	int	ret_code;

	i = 0;
	ret_code = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=')
		ret_code = set_arg(arg, i, data->envs);
	else if (key_is_valid(arg))
		env_insert_node(&data->envs, arg, NULL);
	else if (arg[i] == '\0' && !key_is_valid(arg))
	{
		export_perror(arg);
		ret_code = 1;
	}
	return (ret_code);
}

int	builtin_export(char **argv, t_minishell *data)
{
	int		i;
	int		ret_code;

	i = 1;
	ret_code = 0;
	if (!argv[1])
		print_sorted_envp(data);
	else
	{
		while (argv[i])
		{
			ret_code = select_arg(argv[i], data);
			i++;
		}
	}
	return (ret_code);
}
