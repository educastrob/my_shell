/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/08/29 19:33:01 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_perror(char *error)
{
	if (error)
	{
		write(2, "minishell: ", 11);
		while (*error)
			write(2, error++, 1);
	}
}

int	handle_error(char *error)
{
	if (error)
	{
		ft_perror(error);
		return (1);
	}
	return (0);
}

void	ft_free_tokens(t_token_list *head)
{
	t_token_list	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->token.lexeme != NULL)
			free(head->token.lexeme);
		if (head)
			free(head);
		head = tmp;
	}
}

void	ft_exit(char **line, t_token_list **token_list)
{
	if (*line)
		free(*line);
	if (*token_list)
		ft_free_tokens(*token_list);
	// exit(status);
}

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char **envp)
{
	char			*line;
	t_token_list	*token_list;
	int				i;
	t_minishell		*minishell;
	i = 1;
	minishell = init_minishell(envp);
    env(minishell); // ============ ENV TEST
	while (i)
	{
		line = readline("minishell$ ");
		token_list = get_token_list(line);
		printf("line: %s\n", line);
		print_token_list(token_list); // ============ TOKEN TEST
		if (token_list)
			if (!handle_error(check_syntax(token_list)))
				print_token_list(token_list);
	}

}
