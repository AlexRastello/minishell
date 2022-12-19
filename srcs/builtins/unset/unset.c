/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:32:17 by arastell          #+#    #+#             */
/*   Updated: 2022/12/14 09:49:09 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	unset_valid(char *var)
{
	int		i;

	i = 0;
	if (var[0] && (ft_isdigit(var[0])))
		return (0);
	while (var[i])
	{
		if (var[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	free_del(t_env_list *del)
{
	if (del->key)
		free(del->key);
	if (del->value)
		free(del->value);
	if (del)
		free(del);
}

t_env_list	*unset_del_elem(char *var)
{
	t_env_list	*del;
	t_env_list	*tmp;

	tmp = g_data.env;
	while (tmp)
	{
		if (!ft_strcmp(var, tmp->key))
		{
			del = tmp;
			if (!del->next)
				tmp->prev->next = 0;
			else
				tmp->next->prev = del->prev;
			if (!del->prev)
			{
				tmp->next = del->next;
				tmp->next->prev = 0;
			}
			else
				tmp->prev->next = del->next;
			free_del(del);
		}
		tmp = tmp->next;
	}
	return (g_data.env);
}

t_env_list	*unset_2(char *var)
{
	if (g_data.env && var)
		g_data.env = unset_del_elem(var);
	return (g_data.env);
}

t_env_list	*unset(t_parsing *parse)
{
	int			i;
	int			error;

	error = 0;
	i = 1;
	if (g_data.env)
	{
		while (parse->cmd[i])
		{
			if (unset_valid(parse->cmd[i]))
				g_data.env = unset_del_elem(parse->cmd[i]);
			else
			{
				ft_printf(parse->fd_out, \
				"unset: `%s': not a valid identifier\n", parse->cmd[i]);
				error = 1;
			}
			i++;
		}
	}
	if (error)
		replace_exit_code_builtins(1);
	else
		replace_exit_code_builtins(0);
	return (g_data.env);
}
