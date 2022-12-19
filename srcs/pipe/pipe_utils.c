/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:29:24 by arastell          #+#    #+#             */
/*   Updated: 2022/12/16 14:59:21 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	is_a_empty_cmd(char **cmd)
{
	if (cmd && ft_strlen(cmd[0]) > 0)
		return (0);
	return (1);
}

int	is_a_path_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	get_last_fd(t_fd *lst, int def)
{
	t_fd	*tmp;

	tmp = fd_lstlast(lst);
	if (tmp)
		return (tmp->fd);
	return (def);
}

void	heredoc(char *limiter, int fd_out)
{
	char	*line;
	char	*trim;

	trim = 0;
	line = 0;
	while (1)
	{
		write(0, ">", 1);
		line = get_next_line(0);
		trim = ft_strtrim(line, "\n");
		if (!line || !ft_strncmp(trim, limiter, ft_strlen(line)))
		{
			free_double_str(line, trim);
			break ;
		}
		write(fd_out, line, ft_strlen(line));
		free_double_str(line, trim);
	}
}
