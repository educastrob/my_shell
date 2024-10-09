/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:43:17 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/09 16:02:38 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_cmd(t_tree *tree, t_minishell *data)
{
	int	pid;
	int	ret_code;

	pid = fork();
	execution_signals(pid);
	if (pid == 0)
	{
		fd_list_close_clear(&data->fd_list);
		ret_code = exec_cmd_fork(tree, data);
		free_tree(&data->tree);
		ft_lstiter(data->envs, del_env);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		exit(ret_code);
	}
	return (pid);
}
