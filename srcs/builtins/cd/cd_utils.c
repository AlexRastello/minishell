/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:51:22 by arastell          #+#    #+#             */
/*   Updated: 2022/12/15 16:05:31 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	is_absolute_path(char *path)
{
	if (path[0] == '~')
		return (1);
	return (0);
}

char	*replace_absolute_path(char *path)
{
	char	*path_home;
	char	*to_redir;
	char	*tmp;

	tmp = 0;
	to_redir = 0;
	path_home = get_env("HOME");
	if (!path_home)
	{
		ft_printf(2, "minishell: cd: HOME not set\n");
		replace_exit_code_builtins(1);
	}
	else
	{
		tmp = ft_strtrim(path, "~");
		to_redir = ft_strjoin(path_home, tmp);
		free(tmp);
		free(path_home);
	}
	return (to_redir);
}
