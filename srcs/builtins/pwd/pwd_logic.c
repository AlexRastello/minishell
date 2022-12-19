/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:44:05 by arastell          #+#    #+#             */
/*   Updated: 2022/12/14 15:20:14 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

char	*get_pwd(void)
{
	char	*buffer;
	char	*tmp;

	buffer = malloc(sizeof(char) * 4097);
	tmp = getcwd(buffer, 4096);
	return (tmp);
}	

void	pwd(t_parsing *parse)
{
	char	*tmp;

	tmp = get_pwd();
	ft_printf(parse->fd_out, "%s\n", tmp);
	replace_exit_code_builtins(0);
	free(tmp);
}
