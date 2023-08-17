/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:35:22 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/08/17 14:40:18 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int g_signumm;

// int madd_history(t_mshell *shell)
// {
// 	t_list *new;

// 	new = malloc(sizeof(*new));
// 	if (!shell->hist)
// 	{
// 		shell->hist = new;
// 		shell->hist->cmd = ft_strdup((const char *)shell->prompt);
// 		if (!shell->hist->cmd)
// 			return (1);
// 		shell->hist->next = NULL;
// 	}
// 	else
// 	{
// 		new->next = shell->hist;
// 		shell->hist = new;
// 		shell->hist->cmd = ft_strdup((const char *)shell->prompt);
// 		if (!shell->hist->cmd)
// 			return (1);
// 	}
// 	return (0);
// }

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
	ft_printf("\n\nenvp size = %d\nmenvp size = %d\n\n", get_arr_size(envp), get_arr_size(shell->menvp));
}

int main(int argc, char **argv, char **envp)
{
	t_mshell shell;

	(void)argc;
	(void)argv;
	char *str;

	str = NULL;
	char *line;
	if (envp)
	{
		get_envp(&shell, envp);
		if (get_paths(&shell, shell.menvp))
			return (1);
	}
	else
		shell.paths = NULL;
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
		// madd_history(&shell);
		execution(&shell, envp);
		free(shell.prompt);
		shell.prompt = NULL;
	}
	free_struct(&shell);
}

// shell.cmd = ft_split((const char *)shell.prompt, ' ');
// if (!shell.cmd)
// 	return (free_struct(&shell), 1);
// if (!ft_strncmp((const char *)shell.prompt, "exit", 4))
// 	return (free_struct(&shell), 2);
// else if (!ft_strncmp((const char *)shell.prompt, "echo", 4))
// 			echo_case(shell.prompt);
// else if (!ft_strncmp((const char *)shell.prompt, "cd", 2))
// 		cd_case(&shell);
// else
// {
// 	shell.cmd_count++;
// 	childcmd = fork();
// 	if (childcmd == 0)
// 	{
// 		if(env_case(shell, envp))
// 			return (free_struct(&shell), 1);
// 	}
// }