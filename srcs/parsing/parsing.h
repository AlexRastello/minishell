/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:48:18 by tandre            #+#    #+#             */
/*   Updated: 2022/12/16 11:05:19 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../includes/minishell.h"

t_tokens	*lexer(char *str);
void		tokens_addback(t_tokens **lst, t_tokens *new);
t_tokens	*tokens_new(char *str);
int			infile_simple(t_parsing *p, t_tokens *tok);
void		append_cmd(t_parsing *p, char *str);
int			add_heredoc(t_parsing *p, t_tokens *tok);
int			add_outfile(t_parsing *p, t_tokens *tok);
t_parsing	*parsing(t_tokens *list);
char		*get_env(char *key);
char		*get_key(char *str);
void		expand(t_tokens *list);
char		*new_str(char *str, int i);

#endif
