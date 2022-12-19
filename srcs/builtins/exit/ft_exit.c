/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:36:01 by arastell          #+#    #+#             */
/*   Updated: 2022/12/18 14:29:42 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	return_good_exit_code(int i, char *s)
{
	int	exit_code;

	exit_code = 0;
	if (i != 0)
		exit_code = ft_atoi(s);
	if (s)
		free(s);
	if (exit_code > 255)
		return (exit_code % 256);
	return (exit_code);
}

int	get_exit_code(t_parsing *parse)
{
	int		i;
	char	*trim;

	trim = 0;
	i = 0;
	if (parse->cmd && parse->cmd[1])
		trim = ft_strtrim(parse->cmd[1], " ");
	while (trim && trim[i])
	{
		if (!ft_isdigit(trim[i]))
		{
			ft_printf(2, \
			"minishell: exit: %s: numeric argument required\n", trim);
			free(trim);
			return (255);
		}
		i++;
	}
	return (return_good_exit_code(i, trim));
}

void	ft_exit(t_parsing *parse)
{
	int	exit_prog;
	int	exit_code;

	exit_prog = 0;
	exit_code = get_exit_code(parse);
	if (parse->cmd && parse->cmd[1] && parse->cmd[2])
	{
		ft_printf(2, "minishell: exit: too many arguments\n");
		replace_exit_code_builtins(1);
		return ;
	}
	replace_exit_code_builtins(exit_code);
	ft_printf(parse->fd_out, "exit\n");
	if (parse->fd_in == 0)
		exit_prog = 1;
	if (parse->next)
		exit_prog = 0;
	if (exit_prog)
	{
		free_parsing(parse);
		free_env();
		exit(exit_code);
	}
}
