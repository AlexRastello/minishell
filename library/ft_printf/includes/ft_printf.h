/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:51:31 by arastell          #+#    #+#             */
/*   Updated: 2022/12/13 18:58:37 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "../../libft/libft.h"

int		ft_printf(int fd, const char *s, ...);
int		ft_check(const char *s);
int		ft_printf_str(const char *s, int fd);
int		ft_printf_char(char c, int fd);
int		ft_printf_dec(int n, int fd);
int		ft_printf_unsigned_dec(unsigned int n, int fd);
void	ft_printf_ptr(void *ptr, int *count, int fd);
void	ft_printf_hex(unsigned int n, int *count, int fd);
void	ft_printf_upp_hex(unsigned int n, int *count, int fd);
void	ft_putnbr_hex(unsigned int n, char *s, int *count, int fd);
void	ft_putnbr_ptr(uintptr_t n, char *s, int *count, int fd);

#endif
