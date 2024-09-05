/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/09/04 21:14:45 by fcaldas-         ###   ########.fr       */
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
	char			**args;
	i = 1;
	minishell = init_minishell(envp);
    // env(minishell);
	// pwd();
	while (TRUE)
	{
		line = readline("minishell$ ");
		token_list = get_token_list(line);
		if (token_list)
		{
			if (!handle_error(check_syntax(token_list)))
			{
				args = command_args(token_list);
				if (args)
				{
					if (!ft_strncmp(args[0], "echo", 5))
						ft_echo(args);
					else if (!ft_strncmp(args[0], "pwd", 4))
						pwd();
					else
						ft_printf("minishell: %s: command not found\n", args[0]);
					i = 0;
					while (args[i])
						free(args[i++]);
					free(args);
				}
			}
			ft_free_tokens(token_list);
		}
		// if (token_list)
		// 	if (!handle_error(check_syntax(token_list)))
		// 		print_token_list(token_list);
		
	}

}
