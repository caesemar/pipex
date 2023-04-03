/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:32:08 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/03 02:24:03 by jocasado         ###   ########.fr       */
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
	if (cmd[0] == '.' || cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_arg_setup(cmd, pipex));
		else
			return (NULL);
	}
	else
		return (cmd_path_finder(pipex, cmd));
}

char	*cmd_path_finder(t_pipex *pipex, char *cmd)
{
	char	*f_path;
	char	*temp;
	int		i;

	i = 0;
	if (pipex->cmd_args != NULL)
		ft_free2d(pipex->cmd_args);
	pipex->cmd_args = ft_split(cmd, ' ');
	if (pipex->cmd_args == NULL)
		return (NULL);
	while (pipex->cmd_path[i] != NULL)
	{
		temp = ft_strjoin(pipex->cmd_path[i++], "/");
		f_path = ft_strjoin(temp, pipex->cmd_args[0]);
		free (temp);
		if (access(f_path, X_OK) == 0)
			return (f_path);
		free(f_path);
	}
	return (NULL);
}

void	ft_free2d(char	**tofree)
{
	size_t	i;

	i = 0;
	while (tofree[i])
		free (tofree[i++]);
	free (tofree);
}

char	*ft_arg_setup(char *cmd, t_pipex *pipex)
{
	int		i;
	char	*temp;

	i = 0;
	if (pipex->inputype != 3)
		pipex->inputype = 1;
	else
		pipex->inputype = 2;
	if (pipex->cmd_args != NULL)
		ft_free2d(pipex->cmd_args);
	pipex->cmd_args = ft_split(cmd, '/');
	if (pipex->cmd_args == NULL)
		return (NULL);
	while (pipex->cmd_args[i])
		i++;
	temp = ft_strdup(pipex->cmd_args[i - 1]);
	ft_free2d(pipex->cmd_args);
	pipex->cmd_args = ft_calloc(2, sizeof(char *));
	pipex->cmd_args[0] = ft_strdup(temp);
	free(temp);
	return (cmd);
}
