/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/08/23 18:35:37 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"
#include "lexing.h"

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char **envp)
{
	char			*line;
	t_token_list	*token_list;


	// ============ ENV TEST
	t_env 			*env;
	(void)envp;
	env = *my_env(NULL);
	init_env(envp);
	add_env("$DUDU", "42");
	printf("ENV DUDU VALUE: %s\n", get_env_value("DUDU"));
	free_all_env();

	while (1)
	{
		line = readline("minishell$ ");
		token_list = get_token_list(line);
		if (check_syntax(token_list))
			print_token_list(token_list); 
		

		// ================ TESTS
		// printf("line: %s\n", line);
	}
}
