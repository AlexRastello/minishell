/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:50:53 by arastell          #+#    #+#             */
/*   Updated: 2022/12/12 13:22:25 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"

void	free_tokens(t_tokens *tokens)
{
	t_tokens	*tmp_tokens;

	while (tokens)
	{
		tmp_tokens = tokens->next;
		if (tokens->value)
			free(tokens->value);
		if (tokens)
			free(tokens);
		tokens = tmp_tokens;
	}
}

void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != 0)
	{
		free(strs[i]);
		i++;
	}
	if (strs)
		free(strs);
}

void	free_env(void)
{
	t_env_list	*tmp;

	while (g_data.env)
	{
		tmp = g_data.env->next;
		if (g_data.env->key)
			free(g_data.env->key);
		if (g_data.env->value)
			free(g_data.env->value);
		if (g_data.env)
			free(g_data.env);
		g_data.env = tmp;
	}
}

void	free_fd(t_parsing *parse)
{
	t_fd		*tmp_fd;

	while (parse->infile)
	{
		tmp_fd = parse->infile->next;
		free(parse->infile);
		parse->infile = tmp_fd;
	}
	while (parse->outfile)
	{
		tmp_fd = parse->outfile->next;
		free(parse->outfile);
		parse->outfile = tmp_fd;
	}
}

void	free_parsing(t_parsing *parse)
{
	t_parsing	*tmp_parsing;

	while (parse)
	{
		tmp_parsing = parse->next;
		if (parse->cmd)
			free_split(parse->cmd);
		if (parse->heredoc)
			free(parse->heredoc);
		if (parse->env_path)
			free(parse->env_path);
		free_fd(parse);
		free(parse);
		parse = tmp_parsing;
	}
}
