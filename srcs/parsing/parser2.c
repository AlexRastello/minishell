/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:43:13 by tandre            #+#    #+#             */
/*   Updated: 2022/12/14 15:04:45 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env(char *key)
{
	t_env_list	*temp;

	temp = g_data.env;
	while (temp)
	{
		if (!ft_strncmp(temp->key, key, ft_strlen(temp->key)))
			return (temp->value);
		temp = temp->next;
	}
	return (0);
}

int	infile_simple(t_parsing *p, t_tokens *tok)
{
	int	fd;

	if (!tok)
	{
		ft_printf(2, \
		"minishell: syntax error near unexpected token `newline\n");
		replace_exit_code_builtins(258);
		return (1);
	}
	if (open(tok->value, O_DIRECTORY) > 0)
	{
		ft_printf(2, "minishell: %s: Is a directory\n", tok->value);
		replace_exit_code_builtins(1);
		return (1);
	}
	fd = open(tok->value, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "%s: No such file or directory\n", tok->value);
		replace_exit_code_builtins(1);
		return (1);
	}
	fd_lstadd_back((&p->infile), fd_lstnew(fd));
	return (0);
}

int	add_outfile(t_parsing *p, t_tokens *tok)
{
	int	fd;

	if (!tok->next)
	{
		ft_printf(2, \
		"minishell : syntax error near unexpected token `newline'\n");
		replace_exit_code_builtins(258);
		return (1);
	}
	if (tok->type == 3)
		fd = open(tok->next->value, O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (tok->type == 4)
		fd = open(tok->next->value, O_RDWR | O_APPEND | O_CREAT, 0666);
	fd_lstadd_back(&p->outfile, fd_lstnew(fd));
	return (0);
}

int	add_heredoc(t_parsing *p, t_tokens *tok)
{
	if (!tok)
	{
		ft_printf(2, "bash: syntax error near unexpected token `newline\n");
		return (1);
	}
	p->heredoc = ft_strdup(tok->value);
	return (0);
}

void	append_cmd(t_parsing *p, char *str)
{
	char	**new_tab;
	int		i;

	if (!p->cmd)
	{
		p->cmd = malloc(sizeof(char *) * 2);
		p->cmd[0] = ft_strdup(str);
		p->cmd[1] = 0;
		return ;
	}
	i = 0;
	while (p->cmd[i])
		i ++;
	new_tab = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (p->cmd[i])
	{
		new_tab[i] = ft_strdup(p->cmd[i]);
		i ++;
	}
	new_tab[i] = ft_strdup(str);
	new_tab[i + 1] = 0;
	free_split(p->cmd);
	p->cmd = new_tab;
}
