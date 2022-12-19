/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:29:27 by arastell          #+#    #+#             */
/*   Updated: 2022/12/16 14:58:02 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	**manage_pipe(t_parsing *parse)
{
	int	**fd_pipe;
	int	i;

	fd_pipe = malloc(sizeof(int *) * (parse_lstsize(parse) - 1));
	i = 0;
	while (i < parse_lstsize(parse) - 1)
	{
		fd_pipe[i] = malloc(sizeof(int) * 2);
		pipe(fd_pipe[i]);
		i++;
	}
	return (fd_pipe);
}

void	redir_pipe(t_parsing *parse, int **fd_pipe)
{
	int	i;

	i = 0;
	while (parse)
	{
		if (parse->next)
		{
			parse->next->fd_in = fd_pipe[i][0];
			parse->fd_out = fd_pipe[i][1];
		}
		parse->fd_in = get_last_fd(parse->infile, parse->fd_in);
		parse->fd_out = get_last_fd(parse->outfile, parse->fd_out);
		parse = parse->next;
		i++;
	}
}

void	close_pipe(int size, int **fd_pipe)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		close(fd_pipe[i][0]);
		close(fd_pipe[i][1]);
		i++;
	}
}

void	close_fd(t_parsing *parse)
{
	while (parse)
	{
		if (parse->fd_in != 0)
			close(parse->fd_in);
		if (parse->fd_out != 1)
			close(parse->fd_out);
		parse = parse->next;
	}
}

void	close_and_wait(t_parsing *parse, int **fd_pipe, int *status)
{
	int	size;

	size = parse_lstsize(parse);
	close_pipe(size, fd_pipe);
	close_fd(parse);
	while (1)
	{
		if (waitpid(-1, status, 0) <= 0)
			break ;
		replace_exit_code(*status);
	}
}
