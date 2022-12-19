/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:11:40 by tandre            #+#    #+#             */
/*   Updated: 2022/12/14 15:36:13 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*convert_key(char *str, char *dest)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i ++;
	i ++;
	dest = malloc(sizeof(char) * i);
	ft_strlcpy(dest, str, i);
	return (dest);
}

char	*convert_val(char *str, char *dest)
{
	char	*trim;
	int		start;
	int		end;

	trim = 0;
	start = 0;
	while (str[start] && str[start] != '=')
		start ++;
	if (str[start] != '=')
		return (0);
	start ++;
	end = start;
	while (str[end])
		end ++;
	if (close_double_q(str + start))
		trim = ft_strtrim(str + start, "\"");
	else if (close_single_q(str + start))
		trim = ft_strtrim(str + start, "'");
	else
		trim = ft_strdup(str + start);
	dest = malloc(sizeof(char) * (end - start + 2));
	ft_strlcpy(dest, trim, end - start + 1);
	free(trim);
	return (dest);
}

char	*get_key(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (ft_isalpha(str[i]) || str[i] == '_' || str[i] == '?'))
		i ++;
	return (ft_substr(str, 0, i));
}

void	replace_exit_code_builtins(int status)
{
	t_env_list	*temp;

	temp = g_data.env;
	while (temp)
	{
		if (!ft_strcmp(temp->key, "?"))
		{
			if (temp->value)
				free(temp->value);
			temp->value = ft_itoa(status);
			break ;
		}
		temp = temp->next;
	}
}

void	replace_exit_code(int status)
{
	t_env_list	*temp;

	temp = g_data.env;
	if (WIFEXITED(status))
	{
		while (temp)
		{
			if (!ft_strcmp(temp->key, "?"))
			{
				if (temp->value)
					free(temp->value);
				temp->value = ft_itoa(WEXITSTATUS(status));
				break ;
			}
			temp = temp->next;
		}
	}
}
