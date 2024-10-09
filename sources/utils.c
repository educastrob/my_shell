/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:19:54 by educastro         #+#    #+#             */
/*   Updated: 2024/10/09 02:56:13 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_line_to_readline(t_list *env_list)
{
	int			i;
	int			length;
	char		*line;
	const char	*vars[2] = {find_env_value(env_list, "USER"), \
							find_env_value(env_list, "PWD")};
	const char	*to_print[] = {vars[0], vars[1], ": ", NULL};

	i = 0;
	length = 0;
	while (to_print[i])
		length += ft_strlen(to_print[i++]);
	line = malloc(sizeof(char) * (length + 1));
	i = 1;
	ft_strlcpy(line, to_print[0], length + 1);
	while (to_print[i])
	{
		ft_strlcat(line, to_print[i], length + 1);
		i++;
	}
	free((char *)vars[0]);
	free((char *)vars[1]);
	return (line);
}

int	str_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}
