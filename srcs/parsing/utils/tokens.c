/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:48:47 by tandre            #+#    #+#             */
/*   Updated: 2022/12/16 06:02:16 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	get_type(char *str)
{
	if (!str[0])
		return (0);
	if (str[0] == '<')
		return (1 + (str[1] && str[1] == '<'));
	if (str[0] == '>')
		return (3 + (str[1] && str[1] == '>'));
	if (str[0] == '|')
		return (5 + (str[1] && str[1] == '|'));
	if (str[0] == '&')
		if (str[1] && str[1] == '&')
			return (7);
	return (8);
}

t_tokens	*tokens_new(char *str)
{
	t_tokens	*elem;

	elem = malloc(sizeof(t_tokens));
	elem->next = 0;
	elem->prev = 0;
	elem->type = get_type(str);
	elem->value = str;
	return (elem);
}

void	tokens_addback(t_tokens **lst, t_tokens *new)
{
	t_tokens	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp)
		{
			if (tmp->next == 0)
				break ;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = tmp;
	}
}
