/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/10/18 19:20:00 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

volatile int	g_signal;

static void	init_main(t_main *main, char *envp[])
{
	ft_memset(main, 0, sizeof(*main));
	main->tree = NULL;
	main->token_list = NULL;
	main->ret_code = 0;
	main->line = NULL;
	main->line_to_readline = NULL;
	main->backup_fd_in = dup(STDIN_FILENO);
	ft_memset(&main->data, 0, sizeof(main->data));
	fd_list_add_fd(&main->data.fd_list, main->backup_fd_in);
	main->data.envs = env_create_list(envp);
	env_insert_node(&main->data.envs, "?", "0");
	tcgetattr(STDIN_FILENO, &main->term);
}

static void	aux_main(t_main *main)
{
	main->token_list = get_token_list(main->line);
	main->data.tree = get_tree(main->token_list, &main->data);
	token_clear_list(&main->token_list);
	add_history(main->line);
	free(main->line);
	if (g_signal == SIGINT)
		main->ret_code = 130;
	else
	{
		main->ret_code = exec_tree(main->data.tree, &main->data);
		if (main->data.tree == NULL)
			ft_putendl_fd("syntax error", STDERR_FILENO);
	}
	main->line = ft_itoa(main->ret_code);
	env_insert_node(&main->data.envs, "?", main->line);
	free(main->line);
	free_tree_all(&main->data.tree);
}

static void	close_main(t_main main)
{
	env_clear_list(&main.data.envs);
	fd_list_close_clear(&main.data.fd_list);
	rl_clear_history();
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

static void	valid_main(t_main *main)
{
	init_signals();
	dup2(main->backup_fd_in, STDIN_FILENO);
	tcsetattr(STDIN_FILENO, TCSANOW, &main->term);
	main->line_to_readline = get_line_to_readline(main->data.envs);
	main->line = readline(main->line_to_readline);
	free(main->line_to_readline);
	execution_signals(1);
}

int	main(int argc __attribute__((unused)), \
		char *argv[] __attribute__((unused)), char *envp[])
{
	t_main			main;

	init_main(&main, envp);
	while (g_signal != -1)
	{
		g_signal = 0;
		valid_main(&main);
		if (!main.line)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			break ;
		}
		else if (!main.line[0] || str_is_space(main.line))
		{
			free(main.line);
			continue ;
		}
		aux_main(&main);
	}
	close_main(main);
	return (main.ret_code);
}
