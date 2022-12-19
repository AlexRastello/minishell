/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:29:38 by arastell          #+#    #+#             */
/*   Updated: 2022/12/09 16:47:47 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

static void	cat_path(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i] != 0)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(path[i]) + 10));
		ft_strlcpy(tmp, path[i], ft_strlen(path[i]) + 1);
		ft_strlcat(tmp, "/", ft_strlen(tmp) + 2);
		free(path[i]);
		path[i] = tmp;
		i++;
	}
}

static char	**split_path(char *env_path)
{
	char	**path;

	path = ft_split(env_path, ':');
	cat_path(path);
	return (path);
}

int	is_good_cmd_path(t_parsing *parsing)
{
	char	**env_path;
	char	*join;
	int		i;

	i = 0;
	env_path = 0;
	if (parsing->env_path)
		env_path = split_path(parsing->env_path);
	else
		return (0);
	while (env_path[i] != 0)
	{
		join = ft_strjoin(env_path[i], parsing->cmd[0]);
		if (access(join, F_OK) == 0)
		{
			free(join);
			parsing->cmd[0] = ft_strjoin(env_path[i], parsing->cmd[0]);
			return (1);
		}
		free(join);
		i++;
	}
	return (0);
}
