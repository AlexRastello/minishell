/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:29:31 by arastell          #+#    #+#             */
/*   Updated: 2022/12/18 13:56:45 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	ft_access(t_parsing *parse)
{
	if (access(parse->cmd[0], F_OK) != 0)
	{
		if (!is_good_cmd_path(parse))
		{
			if (is_a_path_cmd(parse->cmd[0]))
				ft_printf(2, \
				"minishell: %s: No such file or directory\n", parse->cmd[0]);
			else
				ft_printf(2, \
				"minishell: %s: command not found\n", parse->cmd[0]);
			exit(127);
		}
	}
}

void	ft_execve(t_parsing *parse, char **envp)
{
	struct stat	stat_cmd;

	if (execve(parse->cmd[0], parse->cmd, envp) == -1)
	{
		stat(parse->cmd[0], &stat_cmd);
		if (S_ISDIR(stat_cmd.st_mode))
			ft_printf(2, \
				"minishell: %s: is a directory\n", parse->cmd[0]);
		else
			perror("Execve");
		exit(126);
	}
}

void	exec_cmd(t_parsing *parse, char **envp)
{
	if (is_a_empty_cmd(parse->cmd))
	{
		ft_printf(2, "minishell: : command not found\n");
		exit(127);
	}
	ft_access(parse);
	ft_execve(parse, envp);
}

void	ft_fork(t_parsing *parse, int **fd_pipe, char **envp, int size)
{
	pid_t	pid;
	int		pipe_tmp[2];

	pid = fork();
	if (pid == 0)
	{
		if (parse->heredoc)
		{
			pipe(pipe_tmp);
			heredoc(parse->heredoc, pipe_tmp[1]);
			dup2(pipe_tmp[0], 0);
		}
		else
		{
			if (parse->fd_in != 0)
				dup2(parse->fd_in, 0);
		}
		if (parse->fd_out != 1)
			dup2(parse->fd_out, 1);
		close(pipe_tmp[0]);
		close(pipe_tmp[1]);
		close_pipe(size, fd_pipe);
		exec_cmd(parse, envp);
	}
	g_data.last_pid = pid;
}

void	ft_pipe(t_parsing *parse, char **envp)
{
	int			**fd_pipe;
	int			size;
	int			status;
	t_parsing	*tmp;

	size = parse_lstsize(parse);
	fd_pipe = manage_pipe(parse);
	redir_pipe(parse, fd_pipe);
	tmp = parse;
	while (tmp)
	{
		if (parse->heredoc)
			g_data.in_heredoc = 1;
		if (is_builtin_rewritten(tmp->cmd))
			manage_builtins(tmp);
		else
			ft_fork(tmp, fd_pipe, envp, size);
		tmp = tmp->next;
	}
	close_and_wait(parse, fd_pipe, &status);
	free_pipe(size, fd_pipe);
	g_data.last_pid = 0;
	g_data.in_heredoc = 0;
}
