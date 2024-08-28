/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/08/28 13:07:50 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char **envp)
{
	char			*line;
	t_token_list	*token_list;
	t_minishell		*minishell;

	// ============ ENV TEST


	minishell = init_minishell(envp);
    print_env(minishell);

	while (1)
	{
		line = readline("minishell$ ");
		token_list = get_token_list(line);
		printf("line: %s\n", line);
		print_token_list(token_list); // ============ TOKEN TEST
	}
}
