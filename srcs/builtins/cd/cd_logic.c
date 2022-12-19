/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:34:08 by arastell          #+#    #+#             */
/*   Updated: 2022/12/15 16:05:16 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	redir_cd(char *path, char *old_pwd)
{
	if (chdir(path))
	{
		ft_printf(2, \
		"minishell: cd: %s: No such file or directory\n", path);
		replace_exit_code_builtins(1);
	}
	else
	{
		replace_exit_code_builtins(0);
		if (old_pwd)
			update_env_pwd(old_pwd);
	}
}

void	absolute_path(char *path, char *old_pwd)
{
	char	*tmp;

	tmp = replace_absolute_path(path);
	if (tmp)
	{
		if (chdir(tmp))
		{
			ft_printf(2, \
			"minishell: cd: %s: No such file or directory: %s\n", tmp);
			replace_exit_code_builtins(1);
		}
		else
		{
			replace_exit_code_builtins(0);
			update_env_pwd(old_pwd);
		}
		free(tmp);
	}
}

void	redir_to_user(char *old_pwd)
{
	char	*to_redir;

	to_redir = get_env("HOME");
	if (!to_redir)
	{
		ft_printf(2, "minishell: cd: HOME not set\n");
		replace_exit_code_builtins(1);
	}
	else
		redir_cd(to_redir, old_pwd);
}

void	cd(t_parsing *parse)
{
	char	*old_pwd;

	old_pwd = get_pwd();
	if (!parse->cmd[1])
		redir_to_user(old_pwd);
	else
	{
		if (parse->cmd[1] && is_absolute_path(parse->cmd[1]))
			absolute_path(parse->cmd[1], old_pwd);
		else
			redir_cd(parse->cmd[1], old_pwd);
	}
	if (old_pwd)
		free(old_pwd);
}
