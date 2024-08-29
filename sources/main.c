/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/08/29 20:04:52 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char **envp)
{
	char			*line;
	t_minishell		*minishell;

	minishell = init_minishell(envp);
    env(minishell); // ============ ENV TEST

	while (TRUE)
	{
		line = readline("minishell$ ");
		minishell->tokens = get_token_list(line);
		printf("line: %s\n", line);
		print_token_list(minishell->tokens); // ============ TOKEN TEST
	}
}
