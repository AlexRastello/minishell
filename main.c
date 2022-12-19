/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:31:19 by arastell          #+#    #+#             */
/*   Updated: 2022/12/18 13:45:25 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_ctl(int n)
{
	struct termios	term;

	tcgetattr(0, &term);
	if (n)
		term.c_lflag |= ECHOCTL;
	else
		term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
}

void	error_tokens(t_tokens *tokens)
{
	free_tokens(tokens);
	replace_exit_code_builtins(258);
}

void	mini_shell(char *line, char **envp)
{
	t_parsing	*par;
	t_tokens	*tokens;

	if (!line)
	{
		free_env();
		exit(0);
	}
	if (*line)
	{
		if (!line_is_empty(line))
			add_history(line);
		tokens = lexer(line);
		free(line);
		if (!tokens)
			return (error_tokens(tokens));
		par = parsing(tokens);
		free_tokens(tokens);
		if (!par)
			return ;
		ft_pipe(par, envp);
		free_parsing(par);
	}
	else
		free(line);
}

int	main(int ac, char **av, char **envp)
{
	char		*line;

	(void) ac;
	(void) av;
	echo_ctl(0);
	g_data.env = init_env_list(envp);
	g_data.in_heredoc = 0;
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	while (1)
	{
		line = readline("$>");
		mini_shell(line, envp);
	}	
	return (0);
}
