/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:50:57 by arastell          #+#    #+#             */
/*   Updated: 2022/12/16 10:03:52 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H

# include "../../includes/minishell.h"

void	free_split(char **strs);
void	free_tokens(t_tokens *tokens);
void	free_parsing(t_parsing *parse);
void	free_env(void);
void	free_pipe(int size, int **fd_pipe);
void	free_double_str(char *s1, char *s2);

#endif