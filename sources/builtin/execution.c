
#include "minishell.h"

int	exec_builtin(t_tree *tree, t_minishell *data)
{

}

int	builtin_process(t_tree *tree, t_minishell *data)
{
	int	ret_code;
	int	prev_fd[2];

	prev_fd[0] = dup(STDIN_FILENO);
	prev_fd[1] = dup(STDOUT_FILENO);
	ret_code = exec_builtin(tree, data);
	dup2(prev_fd[0], STDIN_FILENO);
	dup2(prev_fd[1], STDOUT_FILENO);
	close_pipe(prev_fd);
	return (ret_code);
}
