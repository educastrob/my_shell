/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/08/23 17:06:03 by fcaldas-         ###   ########.fr       */
=======
/*   Updated: 2024/08/14 18:29:05 by educastro        ###   ########.fr       */
>>>>>>> 8ead91a2042d5704b6de60a7fef058f31dee22d0
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char **envp __attribute__((unused)))
{
	char	*line;
	t_token_list	*token_list;

	while (1)
	{
		line = readline("minishell$ ");
		token_list = get_token_list(line);
		check_syntax(token_list);
		print_token_list(token_list); // ============ TEST
		printf("line: %s\n", line);
		printf("token: %s | type: %d", token_list->token.lexeme, token_list->token.type);
	}
}
