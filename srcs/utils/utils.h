/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:29:34 by arastell          #+#    #+#             */
/*   Updated: 2022/12/16 11:04:18 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../../includes/minishell.h"

int			line_is_empty(char *line);
int			is_close(char *str);
void		env_add_back(t_env_list **lst, t_env_list *new);
t_env_list	*env_new(void);
t_env_list	*init_env_list(char **envp);
t_env_list	*update_env_pwd(char *old_pwd);
char		*convert_key(char *str, char *dest);
char		*convert_val(char *str, char *dest);
int			parse_lstsize(t_parsing *lst);
t_parsing	*parse_lstnew(void);
t_parsing	*parse_lstlast(t_parsing *lst);
void		parse_lstadd_back(t_parsing **lst, t_parsing *new);
int			fd_lstsize(t_fd *lst);
t_fd		*fd_lstlast(t_fd *lst);
t_fd		*fd_lstnew(int fd);
void		fd_lstadd_back(t_fd **lst, t_fd *new);
void		replace_exit_code(int status);
void		replace_exit_code_builtins(int status);
char		*convert_str(char *str);

#endif
