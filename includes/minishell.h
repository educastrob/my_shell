/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:40:49 by edcastro          #+#    #+#             */
/*   Updated: 2024/08/23 18:42:49 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H

// libs
# include "../libft/libft.h"

# include "parsing.h"
# include "lexing.h"
# include "expander.h"

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "fcntl.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

#endif