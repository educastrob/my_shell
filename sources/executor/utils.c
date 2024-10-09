/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:09:58 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/09 17:40:37 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	open_redir(char *path_to_file, int type)
{
	int	fd;

	if (type == REDIRECT_INPUT || type == REDIRECT_HEREDOC)
		fd = open(path_to_file, O_RDONLY);
	else if (type == REDIRECT_OUTPUT)
		fd = open(path_to_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == REDIRECT_OUTPUT_APPEND)
		fd = open(path_to_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = -1;
	return (fd);
}

int	is_directory(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == -1)
		return (0);
	return ((((statbuf.st_mode) & 0170000) == (0040000)));
}

void	free_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		free(envp);
		i++;
	}
	if (envp)
		free(envp);
}

void	*select_env(void *content)
{
	t_env	*env;
	char	*env_key;
	char	*env_value;

	env = content;
	env_key = ft_strjoin(env->name, "=");
	env_value = ft_strjoin(env_key, env->value);
	free(env_key);
	return (env_value);
}
