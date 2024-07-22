/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/07/22 20:32:01 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/lexing.h"

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char **envp __attribute__((unused)))
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		get_token_list(line);
		printf("line: %s\n", line);
	}
}
