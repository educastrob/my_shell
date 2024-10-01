/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:33:38 by edcastro          #+#    #+#             */
/*   Updated: 2024/09/30 21:07:45 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	execute_simple_command(t_exec_tree *tree, t_minishell *data)
{
	int	pid;
	int	ret_code;

	pid = exec_cmd(tree, data);
	waitpid(pid, &ret_code, 0);
	ret_code = get_return_value(ret_code);
	return (ret_code);
}

int	exec_tree(t_tree *tree, t_minishell *data)
{
	int	ret_code;

	ret_code = 2;
	if (tree == NULL)
		return (2);
	if (g_signal == SIGINT)
		return (130);
	if (tree->type == COMMAND \
		|| (tree->type >= REDIRECT_INPUT \
			&& tree->type <= REDIRECT_OUTPUT_APPEND))
		ret_code = execute_simple_command(tree, data);
}