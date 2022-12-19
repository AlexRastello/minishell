/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:01:40 by tandre            #+#    #+#             */
/*   Updated: 2022/12/16 11:00:19 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_sep(char c)
{
	return (c == ' ' || c == '|' || c == '&' || c == '<' || c == '>');
}

int	double_sep(char *str, int i, int add)
{
	if (str[i] == '>' || str[i] == '<')
		return (i + (str[i] == str[i + 1]) + add);
	return (i + add);
}

void	create_token(t_tokens **list, char *str, int start, int end)
{
	t_tokens	*new;

	new = tokens_new(ft_substr(str, start, end - start));
	tokens_addback(list, new);
}

int	find_end(char *str, int start, int inside_quotes)
{
	int			end;
	char		c;

	end = start;
	if (is_sep(str[end]))
		return (double_sep(str, end, 1));
	while (str[end] && !is_sep(str[end]))
	{
		while (str[end] && !inside_quotes && !is_sep(str[end]))
		{
			if (str[end] == '\'' || str[end] == '"')
				inside_quotes = 1;
			c = str[end];
			end ++;
		}
		while (str[end] && inside_quotes)
		{
			if (str[end] == c)
				inside_quotes = 0;
			end ++;
		}
	}
	if (!str[end] && inside_quotes)
		return (-1);
	return (end);
}

t_tokens	*lexer(char *str)
{
	t_tokens	*list;
	int			i;
	int			end;

	list = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i ++;
		end = find_end(str, i, 0);
		if (end == -1)
		{
			ft_printf(2, "minishell : error not closing quotes \n");
			return (0);
		}
		create_token(&list, str, i, end);
		i = end;
	}
	expand(list);
	return (list);
}
