/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:34:36 by arastell          #+#    #+#             */
/*   Updated: 2022/12/13 08:13:25 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	close_single_q(char *s)
{
	if (ft_strlen(s) > 0)
	{
		if (s[0] == '\'' && s[ft_strlen(s) - 1] == '\'')
			return (1);
	}
	return (0);
}

int	close_double_q(char *s)
{
	if (ft_strlen(s) > 0)
	{
		if (s[0] == '"' && s[ft_strlen(s) - 1] == '"')
			return (1);
	}
	return (0);
}

int	is_option(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != '-')
			return (0);
		if (i > 0 && s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}
