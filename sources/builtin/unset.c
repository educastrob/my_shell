/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:23:41 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/10/10 01:23:00 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_perror(char *key_value)
{
	int			length;
	char		*message_to_print;
	const char	*message[2] = {"ERROR: unset: '", \
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

int	builtin_unset(char **argv, t_minishell *data)
{
	int	i;
	int	ret_code;

	i = 0;
	ret_code = 0;
	while (argv[i])
	{
		if (key_is_valid(argv[i]))
			delete_env(data, argv[i]);
		else
		{
			unset_perror(argv[i]);
			ret_code = 1;
		}
		i++;
	}
	return (ret_code);
}