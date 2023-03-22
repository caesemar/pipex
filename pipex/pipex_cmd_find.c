/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:32:08 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/22 19:23:03 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*comm_path(char	**envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

char	*cmd_found(t_pipex *pipex, char *cmd)
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

char	*cmd_path_finder(t_pipex *pipex, char *cmd)
{
	char	*f_path;
	char	*temp;

	pipex->cmd_args = ft_split(cmd, ' ');
	while (pipex->cmd_path)
	{
		temp = ft_strjoin(pipex->cmd_path, '/');
		f_path = ft_strjoin(temp, pipex->cmd_args[0]);
		free (temp);
		if (access(f_path, X_OK) == 0)
			return (f_path);
		free(f_path);
		pipex->cmd_path++;
	}
	ft_free2d(pipex->cmd_args);
	ft_free2d(pipex->cmd_path);
	ft_putstr_fd("Command not found", 2);
	exit(1);
}

void	ft_free2d(char	**tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
	{	
		if (tofree[i] != NULL)
			free (tofree[i++]);
	}
	if (tofree != NULL)
		free (tofree);
}

void	full_free(t_pipex *pipex)
{
	ft_free2d(pipex->cmd_args);
	ft_free2d(pipex->cmd_path);
	if (pipex->pipe != NULL)
		free (pipex->pipe);
	if (pipex->cmd_fpath1 != NULL)
		free (pipex->cmd_fpath1);
	if (pipex->cmd_fpath2 != NULL)
		free (pipex->cmd_fpath2);
}
