/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/08/23 17:06:03 by fcaldas-         ###   ########.fr       */
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
	}
}
