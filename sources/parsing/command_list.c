/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:57:41 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/09/05 23:04:26 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	command_list_size(t_token_list *token_list)
{
	size_t	size;
	t_token_list	*tmp;

	size = 0;
	tmp = token_list;
	while (tmp && tmp->token.type == WORD)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

char	**command_args(t_token_list *token_list)
{
	char	**args;
	t_token_list	*tmp;
	size_t	size;
	size_t	i;

	size = command_list_size(token_list);
	args = malloc(sizeof(char *) * (size + 1));
	if (!args)
		return (NULL);
	tmp = token_list;
	i = 0;
	while (tmp && tmp->token.type == WORD)
	{
		args[i] = ft_strdup(tmp->token.lexeme);
		if (!args[i])
		{
			while (i > 0)
				free(args[i--]);
			free(args);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

char	*expand_single_quotes(char *arg)
{
	char	*quotes;

	quotes = NULL;
	if ( arg[0] == '\'' && ft_strlen(arg) > 2)
	{
		quotes = ft_strtrim(arg, "'");
		free(arg);
		return (quotes);
	}
	free(arg);
	return (ft_strdup(" "));
}

char	*expand_double_quotes(char *arg)
{
	char	*quotes;

	quotes = NULL;
	if ( arg[0] == '"' && ft_strlen(arg) > 2)
	{
		quotes = ft_strtrim(arg, "\"");
		free(arg);
		return (quotes);
	}
	free(arg);
	return (ft_strdup(" "));
}

char	*expand(char *arg)
{
	char	*expanded_arg;

	if (!arg)
		return (NULL);

	expanded_arg = ft_strdup(arg);
	if (!expanded_arg)
		return (NULL);
	if (arg[0] == '\'')
		expanded_arg = expand_single_quotes(expanded_arg);
	else if (arg[0] == '"')
		expanded_arg = expand_double_quotes(expanded_arg);

	return (expanded_arg);
}

char	**expand_args(char **args)
{
	char	**expanded_args;
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	expanded_args = malloc(sizeof(char *) * (i + 1));
	if (!expanded_args)
		return (NULL);
	i = 0;
	while (args[i])
	{
		expanded_args[i] = expand(args[i]);
		if (!expanded_args[i])
		{
			while (i > 0)
				free(expanded_args[i--]);
			free(expanded_args);
			return (NULL);
		}
		i++;
	}
	expanded_args[i] = NULL;
	i = 0;
	while (args[i])
		free(args[i++]);
	if (args)	
		free(args);
	return (expanded_args);
}


// char	*expand_env(char *arg)
// {
// 	char	*expanded_arg;
// 	char	*tmp;
// 	char	*env_value;
// 	size_t	i;
// 	int 	g_exit_status = 0;


// 	expanded_arg = ft_strdup(arg);
// 	if (!expanded_arg)
// 		return (NULL);
// 	i = 0;
// 	if (arg && *arg == '"')
// 	{	
// 		while (expanded_arg[i])
// 		{
// 			if (expanded_arg[i] == '$' && expanded_arg[i + 1] == '?')
// 			{
// 				env_value = ft_itoa(g_exit_status);
// 				if (!env_value)
// 				{
// 					free(expanded_arg);
// 					return (NULL);
// 				}
// 				tmp = expanded_arg;
// 				expanded_arg = ft_strjoin(expanded_arg, env_value);
// 				free(tmp);
// 				free(env_value);
// 				if (!expanded_arg)
// 					return (NULL);
// 				i += ft_strlen(env_value);
// 			}
// 			else if (expanded_arg[i] == '$' && expanded_arg[i + 1] == '$')
// 			{
// 				env_value = ft_itoa(getpid());
// 				if (!env_value)
// 				{
// 					free(expanded_arg);
// 					return (NULL);
// 				}
// 				tmp = expanded_arg;
// 				expanded_arg = ft_strjoin(expanded_arg, env_value);
// 				free(tmp);
// 				free(env_value);
// 				if (!expanded_arg)
// 					return (NULL);
// 				i += ft_strlen(env_value);
// 			}

// 		}
// 	}
// 	return (expanded_arg);
// }

