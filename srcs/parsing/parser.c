/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:56:10 by tandre            #+#    #+#             */
/*   Updated: 2022/12/14 09:16:14 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	manage_token(t_tokens *token, t_parsing *p)
{
	if (token->type == 1 || token->type == 2)
	{
		if (token->type == 1 && infile_simple(p, token->next))
			return (1);
		else if (token->type == 2 && add_heredoc(p, token->next))
			return (1);
	}
	else if (token->type == 3 || token->type == 4)
	{
		if (add_outfile(p, token))
			return (1);
	}
	else if (token->type == 8)
		append_cmd(p, token->value);
	return (0);
}

t_tokens	*parsing_1_4(t_tokens *temp)
{
	temp = temp->next;
	if (temp)
	{
		if (temp->type >= 1 && temp->type <= 4)
		{
			ft_printf(2, "minishell : syntax error near unexpected token `'\n");
			replace_exit_code_builtins(258);
			return (0);
		}
	}
	return (temp);
}

t_parsing	*parsing_5(t_tokens *temp, t_parsing *pars)
{
	if (temp->next)
	{
		if (temp->next->type == 5)
		{
			ft_printf(2, "minishell : syntax error near unexpected token `|'\n");
			replace_exit_code_builtins(258);
			return (0);
		}
	}
	pars->next = parse_lstnew();
	pars = pars->next;
	if (!get_env("PATH"))
		pars->env_path = ft_strdup("");
	else
		pars->env_path = ft_strdup(get_env("PATH"));
	return (pars);
}

int	parse_loop(t_tokens *temp, t_parsing *pars)
{
	while (temp)
	{
		if (manage_token(temp, pars) && temp->type != 5)
			return (0);
		if (temp->type >= 1 && temp->type <= 4)
		{
			temp = parsing_1_4(temp);
			if (!temp)
				return (0);
		}
		if (temp->type == 5)
		{
			pars = parsing_5(temp, pars);
			if (!pars)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

t_parsing	*parsing(t_tokens *list)
{
	t_tokens	*temp;
	t_parsing	*p;
	t_parsing	*pars;

	if (!list)
		return (0);
	p = parse_lstnew();
	if (!get_env("PATH"))
		p->env_path = ft_strdup("");
	else
		p->env_path = ft_strdup(get_env("PATH"));
	pars = p;
	temp = list;
	if (!parse_loop(temp, pars))
		return (0);
	return (p);
}
