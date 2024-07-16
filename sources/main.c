/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/07/16 19:23:45 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char **envp __attribute__((unused)))
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		// parser(line);
		printf("line: %s\n", line);
	}
}
