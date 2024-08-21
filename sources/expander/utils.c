/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:37 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/21 12:07:01 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

// permite compartilhar uma unica instancia do env para o código inteiro.
t_env **my_env(t_env *env)
{
	static t_env *env_total;
	
	if (env_total == NULL)
		env_total = env;
	return (&env_total);
}
