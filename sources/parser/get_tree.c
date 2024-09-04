/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:20:14 by educastro         #+#    #+#             */
/*   Updated: 2024/09/04 15:44:52 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tree	*get_tree(t_token_list *token_list, t_minishell *data)
{
	t_tree			*tree;
	t_token_list	*inverted_list = ft_strdup(token_list);

	tree = make_tree(inverted_list, data);
	token_clear_list(&inverted_list);
	return (tree);
}