/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:19:16 by arastell          #+#    #+#             */
/*   Updated: 2022/12/16 10:03:41 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"

void	free_pipe(int size, int **fd_pipe)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		free(fd_pipe[i]);
		i++;
	}
	free(fd_pipe);
}

void	free_double_str(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}
