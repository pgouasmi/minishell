/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:48:14 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/07/20 13:10:22 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int env_case(t_mshell *shell)
{
	size_t	j;
	char	*temp;

	j = -1;
	while (shell->paths[++j])
	{
		temp = ft_strjoin(shell->paths[j], shell->cmd[0]);
		if (!temp)
			return (2);
		if ((execve(temp, shell->cmd, NULL)) == -1)
			free(temp);
	}
	return (1);
}