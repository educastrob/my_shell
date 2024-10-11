#include "../../includes/expander.h"
#include "../../includes/environment.h"
#include "../../includes/executor.h"

int	envp_list_size(t_list *head)
{
	int			i;
	t_list	*aux;

	i = 0;
	aux = head;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

static t_env	*env_create_node(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->name = ft_strdup(key);
	if (value)
		new_node->value = ft_strdup(value);
	else
		new_node->value = NULL;
	return (new_node);
}

int	att_existing_value(t_list *head, char *key, char *value)
{
	t_list	*temp;
	t_env	*env;

	temp = head;
	while (temp != NULL && key)
	{
		env = (t_env *)temp->content; 
		if (ft_strncmp(env->name, key, -1) == 0)
		{
			free(env->value);
			env->value = ft_strdup(value);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}


void	env_insert_node(t_list **head, char *key, char *value)
{
	t_list	*new_node;
	t_list	*temp;

	if (!head || !key)
		return ;
	if (att_existing_value(*head, key, value) == 1)
		return ;
	new_node = ft_lstnew(env_create_node(key, value));
	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}
