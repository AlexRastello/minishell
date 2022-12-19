/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:27:43 by arastell          #+#    #+#             */
/*   Updated: 2022/12/08 17:28:25 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_fd	*fd_lstlast(t_fd *lst)
{
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	fd_lstsize(t_fd *lst)
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

t_fd	*fd_lstnew(int fd)
{
	t_fd	*new;

	new = malloc(sizeof(t_fd));
	new->fd = fd;
	new->next = 0;
	return (new);
}

void	fd_lstadd_back(t_fd **lst, t_fd *new)
{
	t_fd	*tmp;

	tmp = 0;
	if (!(*lst))
		*lst = new;
	else
	{
		tmp = fd_lstlast(*lst);
		tmp->next = new;
	}
}
