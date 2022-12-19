/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:45:28 by arastell          #+#    #+#             */
/*   Updated: 2022/12/13 19:08:08 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_ptr(void *ptr, int *count, int fd)
{
	if ((uintptr_t) ptr == 0)
		*count += ft_printf_str("0x0", fd);
	else
	{
		*count += ft_printf_str("0x", fd);
		ft_putnbr_ptr((uintptr_t) ptr, "0123456789abcdef", count, fd);
	}
}
