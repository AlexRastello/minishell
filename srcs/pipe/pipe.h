/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:29:21 by arastell          #+#    #+#             */
/*   Updated: 2022/12/16 14:56:46 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "../../includes/minishell.h"

int		**manage_pipe(t_parsing *parse);
int		is_good_cmd_path(t_parsing *parsing);
int		is_a_empty_cmd(char **cmd);
int		get_last_fd(t_fd *lst, int def);
int		is_a_path_cmd(char *cmd);
void	ft_pipe(t_parsing *parse, char **envp);
void	heredoc(char *limiter, int fd_out);
void	redir_pipe(t_parsing *parse, int **fd_pipe);
void	close_pipe(int size, int **fd_pipe);
void	close_fd(t_parsing *parse);
void	close_and_wait(t_parsing *parse, int **fd_pipe, int *status);

#endif
