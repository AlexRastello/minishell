/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:47:09 by arastell          #+#    #+#             */
/*   Updated: 2022/12/16 09:25:16 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "structures.h"
# include "../srcs/free/ft_free.h"
# include "../library/ft_printf/includes/ft_printf.h"
# include "../library/libft/libft.h"
# include "../library/gnl/get_next_line.h"
# include "../srcs/builtins/builtins.h"
# include "../srcs/utils/utils.h"
# include "../srcs/parsing/parsing.h"
# include "../srcs/pipe/pipe.h"
# include "../srcs/signal/handler.h"

t_global	g_data;

#endif
