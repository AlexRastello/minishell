/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:36:08 by arastell          #+#    #+#             */
/*   Updated: 2022/12/13 19:00:12 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_dec(int n, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_itoa(n);
	i = ft_printf_str(tmp, fd);
	if (tmp)
		free(tmp);
	return (i);
}

int	ft_printf_unsigned_dec(unsigned int n, int fd)
{
	char	*tmp;
	int		i;

	tmp = ft_itoa_unsigned(n);
	i = 0;
	i = ft_printf_str(tmp, fd);
	if (tmp)
		free(tmp);
	return (i);
}
