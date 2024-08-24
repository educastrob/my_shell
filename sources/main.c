/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/08/24 16:15:29 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char *envp[])
{
	t_env			**env = NULL;
	char			*line;
	t_token_list	*token_list;


	// ============ ENV TEST
	init_env(env, envp);
	print_env(env);
	free_all_env(env);

	while (1)
	{
		line = readline("minishell$ ");
		token_list = get_token_list(line);
		printf("line: %s\n", line);
		print_token_list(token_list); // ============ TOKEN TEST
	}
}
