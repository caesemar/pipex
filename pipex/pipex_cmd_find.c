/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:32:08 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/21 19:33:15 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*comm_path(char	**envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

char	*cmd_found(t_pipex pipex, char *cmd)
{
	char	*f_path;

	if (cmd[0] == '.' || cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			return (NULL);
	}
	else
		return (cmd_path_finder(pipex, cmd));
	return (NULL);
}

char	*cmd_path_finder(t_pipex pipex, char *cmd)
{
	char	*f_path;
	char	*temp;

	pipex.cmd_args = ft_split(cmd, ' ');
	while (*pipex.cmd_path)
	{
		temp = ft_strjoin(pipex.cmd_path, '/');
		f_path = ft_strjoin(temp, pipex.cmd_args[0]);
		free (temp);
		if (access(f_path, X_OK) == 0)
		{
			//free (pipex.cmd_args); //liberar bien.
			return (f_path);
		}
		free(f_path);
		pipex.cmd_path++;
	}
	free (pipex.cmd_args);
	perror("Command not found"); //printf? 
	exit(-1);
}
