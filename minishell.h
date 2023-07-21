/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:52:08 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/20 21:19:52 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_mshell
{
	char *prompt;
	char **cmd;
	char **paths;
	char **temp;
	char *zero;
}		t_mshell;

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>
# include "./includes/libft.h"

int		get_paths(t_mshell *shell, char **envp);
size_t	count_arr_size(char **arr);
void	print_arr(char **arr);
void	free_struct(t_mshell *shell);
void	free_arr(char **arr);
int 	env_case(t_mshell *shell);




#endif