/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/09/05 23:07:30 by nasser           ###   ########.fr       */
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
	exit(0);
}

int	main(int argc __attribute__((unused)), \
	char **argv __attribute__((unused)), char **envp)
{
	char			*line;
	t_token_list	*token_list;
	int				i;
	char			**args;
	i = 1;
	t_minishell		*minishell;
	minishell = init_minishell(envp);
    env(minishell);
	pwd();
	while (TRUE)
	{
		line = readline("minishell$ ");
		token_list = get_token_list(line);	
		if (token_list)
		{
			if (!handle_error(check_syntax(token_list)))
			{
				args = command_args(token_list);
				args = expand_args(args);
				if (args && args[0])
				{
					// printf("args[0]: %s\n", args[0]);
					if (!ft_strncmp(args[0], "echo", 4))
						ft_echo(args);
					else if (!ft_strncmp(args[0], "pwd", 3))
						pwd();
					else if (!ft_strncmp(args[0], "env", 3))
						env(minishell);
					else if (!ft_strncmp(args[0], "exit", 4))
						ft_exit(&line, &token_list);
					else
						ft_printf("minishell: %s: command not found\n", args[0]);
					i = 0;
					while (args[i])
						free(args[i++]);
					if (args)
						free(args);
				}
			}
			ft_free_tokens(token_list);
		}
		free(line);
		// if (token_list)
		// 	if (!handle_error(check_syntax(token_list)))
		// 		print_token_list(token_list);
		
	}

}
