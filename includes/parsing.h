/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:38:39 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/08/29 19:39:34 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

# define TRUE 1
# define FALSE 0


char	*check_syntax(t_token_list *token_list);

typedef struct s_command
{
	char				*name;
	char				**argv;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;