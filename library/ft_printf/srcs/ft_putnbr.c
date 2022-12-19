/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:58:26 by arastell          #+#    #+#             */
/*   Updated: 2022/12/13 19:00:49 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_hex(unsigned int nbr, char *base, int *count, int fd)
{
	if (nbr > 15)
	{
		ft_putnbr_hex(nbr / 16, base, count, fd);
		ft_putnbr_hex(nbr % 16, base, count, fd);
	}
	else
	{
		write(fd, &base[nbr], 1);
		*count += 1;
	}
}

void	ft_putnbr_ptr(uintptr_t nbr, char *base, int *count, int fd)
{
	if (nbr > 15)
	{
		ft_putnbr_ptr(nbr / 16, base, count, fd);
		ft_putnbr_ptr(nbr % 16, base, count, fd);
	}
	else
	{
		write(fd, &base[nbr], 1);
		*count += 1;
	}
}
