/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:51:32 by arastell          #+#    #+#             */
/*   Updated: 2022/12/13 18:59:09 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_printf_switch(va_list args, int check, int *count, int fd)
{
	if (check == 1)
		*count += ft_printf_char(va_arg(args, int), fd);
	else if (check == 2)
		*count += ft_printf_str(va_arg(args, char *), fd);
	else if (check == 3)
		ft_printf_ptr(va_arg(args, void *), count, fd);
	else if (check == 4 || check == 5)
		*count += ft_printf_dec(va_arg(args, int), fd);
	else if (check == 6)
		*count += ft_printf_unsigned_dec(va_arg(args, unsigned int), fd);
	else if (check == 7)
		ft_printf_hex(va_arg(args, unsigned int), count, fd);
	else if (check == 8)
		ft_printf_upp_hex(va_arg(args, unsigned int), count, fd);
	else if (check == 9)
		*count += ft_printf_char('%', fd);
}

int	ft_printf(int fd, const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (ft_check(s + i) > 0)
		{
			ft_printf_switch(args, ft_check(s + i), &count, fd);
			i += 2;
			continue ;
		}
		count += ft_printf_char(s[i], fd);
		i++;
	}
	va_end(args);
	return (count);
}
