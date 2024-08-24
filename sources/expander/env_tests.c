/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:08:19 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/24 16:16:21 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expander.h"

void print_env(t_env **env)
{
    while (env) {
        printf("%s=%s\n", (*env)->name, (*env)->value);
        env = &(*env)->next;
    }
}
