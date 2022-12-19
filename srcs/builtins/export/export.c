/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:36:14 by arastell          #+#    #+#             */
/*   Updated: 2022/12/14 16:47:50 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	is_affect(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	print_export(t_parsing *parse)
{
	t_env_list	*temp;

	temp = g_data.env;
	while (temp)
	{
		if (!(temp->key[0] == '?'))
		{
			if (temp->value)
				ft_printf(parse->fd_out, "declare -x %s=\"%s\"\n", \
					temp->key, temp->value);
			else
				ft_printf(parse->fd_out, "declare -x %s\n", temp->key);
		}
		temp = temp->next;
	}
}

int	valid_export(char *cmd)
{
	int		i;

	i = 0;
	if (cmd[0] && (ft_isdigit(cmd[0]) || cmd[0] == '='))
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '!')
			return (0);
		if (!ft_isdigit(cmd[i]))
			return (1);
		i++;
	}
	return (0);
}

void	add_elem(char *cmd)
{
	t_env_list	*new;

	new = env_new();
	new->key = convert_key(cmd, new->key);
	new->value = convert_val(cmd, new->value);
	if (!new->value && is_affect(cmd))
		new->value = ft_strdup("");
	g_data.env = unset_2(new->key);
	env_add_back(&g_data.env, new);
}

void	export(t_parsing *parse)
{
	int			i;
	int			error;

	error = 0;
	i = 1;
	if (!parse->cmd[i])
		print_export(parse);
	while (parse->cmd[i])
	{
		if (valid_export(parse->cmd[i]))
			add_elem(parse->cmd[i]);
		else
		{
			ft_printf(2, \
			"minishell: export: `%s': not a valid identifier\n", \
			parse->cmd[i]);
			error = 1;
		}
		i++;
	}
	if (error)
		replace_exit_code_builtins(1);
	else
		replace_exit_code_builtins(0);
}
