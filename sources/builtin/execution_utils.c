#include "minishell.h"

int	key_is_valid(char *key)
{
	int	i;

	i = 0;
	if (ft_isdigit(key[0]))
		return (0);
	while (key[i] && (ft_isalnum(key[i]) || key[i] == '_'))
		i++;
	if (key[i] == '\0')
		return (1);
	return (0);
}


int	verify_builtin(char *command)
{
	if (command)
	{
	if (ft_strncmp(command, "echo", -1) == 0)
		return (1);
	if (ft_strncmp(command, "cd", -1) == 0)
		return (1);
	if (ft_strncmp(command, "pwd", -1) == 0)
		return (1);
	if (ft_strncmp(command, "export", -1) == 0)
		return (1);
	if (ft_strncmp(command, "unset", -1) == 0)
		return (1);
	if (ft_strncmp(command, "env", -1) == 0)
		return (1);
	if (ft_strncmp(command, "exit", -1) == 0)
		return (1);
	}
	return (0);
}

int	is_builtin(t_tree *tree)
{
	int		builtin_veryfied;

	if(!tree)
		return (0);
	builtin_veryfied = 0;
	if (tree->type == COMMAND && tree->command)
		builtin_veryfied = verify_builtin(tree->command->token.lexeme);
	else
		builtin_veryfied = verify_builtin(tree->right);
	return (builtin_veryfied);
}
