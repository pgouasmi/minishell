/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:35:22 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/20 21:20:36 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_mshell shell;

	(void) argc;
	(void) argv;
	
	if (get_paths(&shell, envp))
		return (free_struct(&shell), 1);
	while (1)
	{
		shell.prompt = get_next_line(1);
		if (!shell.prompt)
			return (free_struct(&shell), 1);
		shell.cmd = ft_split((const char*)shell.prompt, ' ');
		if (!shell.cmd)
			return (free_struct(&shell), 1);
		if (!ft_strncmp((const char *)shell.prompt, "exit", 4))
			return (free_struct(&shell), 2);
		if (!ft_strncmp((const char *)shell.prompt, "env", 3))
		{
			if (env_case(&shell))
				return (free_struct(&shell), 1);
		}
		printf("got : %s\n", shell.prompt);
		free(shell.prompt);
		free_arr(shell.cmd);
	}
}
