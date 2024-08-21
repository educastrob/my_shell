/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 05:11:02 by educastro         #+#    #+#             */
/*   Updated: 2024/08/21 07:10:56 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_envp_list	*get_envp_list(char *key, char *value)
{
	t_envp_list		*new_node;
	
	new_node = malloc(sizeof(t_envp_list));
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
}