/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:28:38 by arastell          #+#    #+#             */
/*   Updated: 2022/12/12 08:04:49 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_parsing	*parse_lstlast(t_parsing *lst)
{
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	parse_lstsize(t_parsing *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_parsing	*parse_lstnew(void)
{
	t_parsing	*new;

	new = malloc(sizeof(t_parsing) * 1);
	new->next = 0;
	new->cmd = 0;
	new->heredoc = 0;
	new->fd_in = 0;
	new->fd_out = 1;
	new->infile = 0;
	new->infile = 0;
	new->outfile = 0;
	new->outfile = 0;
	return (new);
}

void	parse_lstadd_back(t_parsing **lst, t_parsing *new)
{
	t_parsing	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = parse_lstlast(*lst);
		tmp->next = new;
	}
}
