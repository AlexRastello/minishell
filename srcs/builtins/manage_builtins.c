/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:44:56 by arastell          #+#    #+#             */
/*   Updated: 2022/12/12 13:20:25 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_builtin_rewritten(char **cmd)
{
	if (cmd && cmd[0])
	{
		if (!ft_strcmp(cmd[0], "echo"))
			return (1);
		else if (!ft_strcmp(cmd[0], "cd"))
			return (1);
		else if (!ft_strcmp(cmd[0], "pwd"))
			return (1);
		else if (!ft_strcmp(cmd[0], "export"))
			return (1);
		else if (!ft_strcmp(cmd[0], "unset"))
			return (1);
		else if (!ft_strcmp(cmd[0], "env"))
			return (1);
		else if (!ft_strcmp(cmd[0], "exit"))
			return (1);
	}
	return (0);
}

void	manage_builtins(t_parsing *parse)
{
	if (parse->cmd && parse->cmd[0])
	{
		if (!ft_strcmp(parse->cmd[0], "echo"))
			ft_echo(parse);
		else if (!ft_strcmp(parse->cmd[0], "cd"))
			cd(parse);
		else if (!ft_strcmp(parse->cmd[0], "pwd"))
			pwd(parse);
		else if (!ft_strcmp(parse->cmd[0], "export"))
			export(parse);
		else if (!ft_strcmp(parse->cmd[0], "unset"))
			g_data.env = unset(parse);
		else if (!ft_strcmp(parse->cmd[0], "env"))
			env(parse);
		else if (!ft_strcmp(parse->cmd[0], "exit"))
			ft_exit(parse);
	}
}
