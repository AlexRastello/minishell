/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:34:33 by arastell          #+#    #+#             */
/*   Updated: 2022/12/14 16:00:25 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	ft_echo(t_parsing *parse)
{
	int		i;
	int		option;

	option = 0;
	i = 1;
	while (parse->cmd[i] && is_option(parse->cmd[i]))
	{
		option = 1;
		i++;
	}
	while (parse->cmd[i])
	{
		ft_printf(parse->fd_out, "%s", parse->cmd[i]);
		i++;
		if (parse->cmd[i] && ft_strlen(parse->cmd[i]))
			ft_printf(parse->fd_out, " ");
	}
	if (!option)
		ft_printf(parse->fd_out, "\n");
	replace_exit_code_builtins(0);
}
