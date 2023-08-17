/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:35:22 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/08/17 16:13:23 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t get_arr_size(char **arr)
{
	size_t i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char **copy_tab(char **envp, size_t size)
{
	char **arr;
	size_t j;

	arr = malloc(sizeof(char *) * size + 1);
	if (!arr)
		return (NULL);
	arr[size] = NULL;
	j = 0;
	while (j < size - 1)
	{
		arr[j] = ft_strdup(envp[j]);
		if (!arr[j])
			return (NULL);
		j++;
	}
	return (arr);
}

void get_envp(t_mshell *shell, char **envp)
{
	shell->envp_size = get_arr_size(envp);
	if (shell->envp_size == 0)
		return (free_struct(shell), exit(1));
	shell->menvp = copy_tab(envp, shell->envp_size + 1);
	if (!shell->menvp)
		return (free_struct(shell), exit(2));



	ft_printf("\n\n\n\n\n\ncopied envp :\n\n\n\n\n\n");
	print_arr(shell->menvp);
	ft_printf("\n\n\n\n\n\n");
}

int main(int argc, char **argv, char **envp)
{
	t_mshell shell;

	(void)argc;
	(void)argv;

	char *line;
	if (envp)
	{
		get_envp(&shell, envp);
		if (get_paths(&shell, shell.menvp))
			return (1);
	}
	else
		shell.paths = NULL;

	ft_printf("\n\n\n\n\n\nmain envp :\n");
	print_arr(envp);


	while (1)
	{
		ft_printf("%s ", shell.join_user);
		line = get_next_line(0);
		if (!line)
			return (free_struct(&shell), 1);
		shell.prompt = ft_strtrim((const char *)line, "\n");
		free(line);
		if (!shell.prompt)
			return (free_struct(&shell), 1);
		tokenizer(&shell);
		execution(&shell, envp);
		free(shell.prompt);
		shell.prompt = NULL;
	}
	free_struct(&shell);
}