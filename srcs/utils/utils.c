/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:54:49 by arastell          #+#    #+#             */
/*   Updated: 2022/12/16 11:04:03 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] > 32)
			return (0);
		i++;
	}
	return (1);
}

int	is_close(char *str)
{
	int	i;
	int	count;
	int	type;

	i = 0;
	count = 0;
	type = 0;
	while (str[i])
	{
		if (count == 0 && (str[i] == '\'' || str[i] == '"'))
			type = str[i];
		if (str[i] == type)
			count++;
		i++;
	}
	if (count % 2)
		return (0);
	return (1);
}

char	*convert_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$')
		i ++;
	if (str[i] == '$')
		str = new_str(str, i);
	return (str);
}
