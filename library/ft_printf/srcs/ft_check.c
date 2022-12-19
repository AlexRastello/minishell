/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:33:15 by arastell          #+#    #+#             */
/*   Updated: 2022/11/11 13:17:57 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check(const char *s)
{
	if (s[0] == '%')
	{
		if (s[1] == 'c')
			return (1);
		else if (s[1] == 's')
			return (2);
		else if (s[1] == 'p')
			return (3);
		else if (s[1] == 'd')
			return (4);
		else if (s[1] == 'i')
			return (5);
		else if (s[1] == 'u')
			return (6);
		else if (s[1] == 'x')
			return (7);
		else if (s[1] == 'X')
			return (8);
		else if (s[1] == '%')
			return (9);
	}
	return (0);
}
