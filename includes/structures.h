/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:47:16 by arastell          #+#    #+#             */
/*   Updated: 2022/12/15 16:42:40 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*prev;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_parsing
{
	char				**cmd;
	char				*heredoc;
	char				*env_path;
	struct s_fd			*infile;
	struct s_fd			*outfile;
	int					fd_heredoc;
	int					fd_in;
	int					fd_out;
	struct s_parsing	*next;
}	t_parsing;

typedef struct s_fd
{
	int			fd;
	struct s_fd	*next;
}	t_fd;

typedef struct s_tokens
{
	int				type;
	char			*value;
	int				inter;
	int				quotes;
	struct s_tokens	*prev;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_global
{
	struct s_env_list	*env;
	pid_t				last_pid;
	int					in_heredoc;
}	t_global;

#endif
