/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:11:33 by tandre            #+#    #+#             */
/*   Updated: 2022/12/14 09:43:22 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_env_list	*env_last(t_env_list *lst)
{
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	env_add_back(t_env_list **lst, t_env_list *new)
{
	t_env_list	*tmp;

	tmp = 0;
	if (!(*lst) || !lst)
		*lst = new;
	else
	{
		tmp = env_last(*lst);
		tmp->next = new;
		new->prev = tmp;
		new->next = 0;
	}
}

t_env_list	*env_new(void)
{
	t_env_list	*tmp;

	tmp = malloc(sizeof(t_env_list) * 1);
	if (!tmp)
		return (0);
	tmp->key = 0;
	tmp->value = 0;
	tmp->next = 0;
	tmp->prev = 0;
	return (tmp);
}

t_env_list	*init_env_list(char **envp)
{
	int			i;
	t_env_list	*new;
	t_env_list	*env;

	env = 0;
	i = 0;
	while (envp[i])
	{
		new = env_new();
		new->key = convert_key(envp[i], new->key);
		new->value = convert_val(envp[i], new->value);
		env_add_back(&env, new);
		i ++;
	}
	new = env_new();
	new->key = ft_strdup("?");
	new->value = ft_strdup("0");
	env_add_back(&env, new);
	return (env);
}
