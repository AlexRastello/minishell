/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:34:47 by arastell          #+#    #+#             */
/*   Updated: 2022/12/12 13:22:01 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	env(t_parsing *parse)
{
	t_env_list	*temp;

	temp = g_data.env;
	if (parse->cmd[1])
	{
		ft_printf(parse->fd_out, \
			"env: %s: No such file or directory\n", parse->cmd[1]);
		replace_exit_code_builtins(127);
		return (0);
	}
	while (temp)
	{
		if (temp->value)
		{
			if (!(temp->key[0] == '?'))
				ft_printf(parse->fd_out, "%s=%s\n", temp->key, temp->value);
		}
		temp = temp->next;
	}
	replace_exit_code_builtins(0);
	return (0);
}
