/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:08 by educastro         #+#    #+#             */
/*   Updated: 2024/10/09 01:43:45 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	prepare_and_execute_pipe(t_tree *tree, t_minishell *data)
{
	int	pid;
	int	old_fd[2];
	int	pipe_fd[2];

	pipe(pipe_fd);
	old_fd[0] = dup(STDIN_FILENO);
	old_fd[1] = dup(STDOUT_FILENO);
	fd_list_add_fd(&data->fd_list, old_fd[0]);
	fd_list_add_fd(&data->fd_list, old_fd[1]);
	fd_list_add_fd(&data->fd_list, pipe_fd[0]);
	fd_list_add_fd(&data->fd_list, pipe_fd[1]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	exec_pipe(tree->left, data);
	dup2(old_fd[1], STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	pid = exec_pipe(tree->right, data);
	dup2(old_fd[0], STDIN_FILENO);
	return (pid);
}

int	exec_pipe(t_tree *tree, t_minishell *data)
{
	int			pid;

	pid = -1;
	if (g_signal != 0)
		return (1);
	if (tree->type == PIPE)
		pid = prepare_and_execute_pipe(tree, data);
	else if (tree->type == COMMAND
		|| (tree->type >= REDIRECT_INPUT
			&& tree->type <= REDIRECT_OUTPUT_APPEND))
		pid = exec_cmd(tree, data);
	return (pid);
}
