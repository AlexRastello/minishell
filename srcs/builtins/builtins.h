/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:44:23 by arastell          #+#    #+#             */
/*   Updated: 2022/12/15 16:02:44 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../../includes/minishell.h"

int			is_builtin_rewritten(char **cmd);
int			close_single_q(char *s);
int			close_double_q(char *s);
int			is_option(char *s);
int			env(t_parsing *parse);
int			is_absolute_path(char *path);
void		ft_echo(t_parsing *parse);
void		manage_builtins(t_parsing *parse);
void		cd(t_parsing *parse);
void		ft_exit(t_parsing *parse);
void		export(t_parsing *parse);
void		pwd(t_parsing *parse);
char		*get_pwd(void);
char		*replace_absolute_path(char *path);
t_env_list	*unset(t_parsing *parse);
t_env_list	*unset_2(char *var);

#endif
