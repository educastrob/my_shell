/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/08/21 12:49:04 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char **envp __attribute__((unused)))
{
	char	*line;
	t_token_list	*token_list;

	while (1)
	{
		line = readline("minishell$ ");
		token_list = get_token_list(line);
		printf("line: %s\n", line);
		print_token_list(token_list); // ============ TOKEN TEST
	}
}
