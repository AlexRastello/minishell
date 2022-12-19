/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:12:17 by tandre            #+#    #+#             */
/*   Updated: 2022/12/18 13:44:34 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*new_str(char *str, int i)
{
	char		*save;
	char		*key;
	char		*tp;
	char		*res;

	tp = 0;
	res = ft_substr(str, 0, i);
	save = ft_substr(str, i + 1, ft_strlen(str));
	key = get_key(save);
	if (!get_env(key))
		res = ft_strjoin_free(res, save + ft_strlen(key));
	else
	{
		res = ft_strjoin_free(res, get_env(key));
		tp = ft_substr(save, ft_strlen(key), ft_strlen(save));
		res = ft_strjoin_free(res, tp);
	}
	free(key);
	free(save);
	if (tp)
		free(tp);
	free(str);
	return (res);
}

int	quotes(t_tokens *temp, int start, char c)
{
	int			end;
	int			len;
	char		*save;
	char		*res;

	save = ft_substr(temp->value, 0, start);
	end = start + 1;
	while (temp->value[end] && temp->value[end] != c)
		end ++;
	if (!temp->value[end])
	{
		free(save);
		return (0);
	}
	res = ft_substr(temp->value, start + 1, end - start - 1);
	res = ft_strjoin_2(save, res);
	free(save);
	len = ft_strlen(res);
	res = ft_strjoin_free(res, temp->value + end + 1);
	if (res)
	{
		free(temp->value);
		temp->value = res;
	}
	return (len);
}

int	update_status(int status, char c)
{
	if (status == 1)
		if (c == '\'')
			return (0);
	if (status == 2)
		if (c == '"')
			return (0);
	if (status == 0)
	{
		if (c == '\'')
			return (1);
		else if (c == '"')
			return (2);
	}
	return (status);
}

void	expand_env(t_tokens *temp, int i, int status)
{
	char	*res;

	while (temp->value[i])
	{
		if (temp->value[i] == '$' && status != 1
			&& (ft_isalpha(temp->value[i + 1]) || temp->value[i + 1] == '_'
				|| temp->value[i + 1] == '?'))
		{
			res = new_str(temp->value, i);
			if (res)
			{
				temp->value = ft_strdup(res);
				free(res);
			}
			status = 0;
			i = 0;
		}
		status = update_status(status, temp->value[i]);
		i ++;
	}
}

void	expand(t_tokens *list)
{
	t_tokens	*temp;
	int			i;

	temp = list;
	while (temp)
	{
		expand_env(temp, 0, 0);
		i = 0;
		while (temp->value[i])
		{
			if ((temp->value[i] == '\'' || temp->value[i] == '"'))
				i = quotes(temp, i, temp->value[i]) - 1;
			i ++;
		}
		temp = temp->next;
	}
}
