/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:54:55 by arastell          #+#    #+#             */
/*   Updated: 2022/12/18 13:53:38 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"

void	handler_sigquit(void)
{
	if (!rl_done)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	if (g_data.last_pid != 0)
	{
		ft_printf(2, "^\\Quit: 3\n");
		replace_exit_code_builtins(131);
	}
	else
		replace_exit_code_builtins(1);
	if (g_data.in_heredoc)
		g_data.in_heredoc = 0;
}

void	handler_sigint(void)
{
	if (!g_data.in_heredoc)
	{
		if (g_data.last_pid != 0)
		{
			ft_printf(2, "^C");
			replace_exit_code_builtins(130);
		}
		else
			replace_exit_code_builtins(1);
		write(1, "\n", 1);
		if (!rl_done)
		{
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
	}
	if (g_data.last_pid != 0 && g_data.in_heredoc)
	{
		kill(g_data.last_pid, SIGKILL);
		g_data.in_heredoc = 0;
		write(1, "\n", 1);
		replace_exit_code_builtins(1);
	}
}

void	handler(int num)
{
	if (num == SIGQUIT)
		handler_sigquit();
	if (num == SIGINT)
		handler_sigint();
}
