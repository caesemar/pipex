/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:32:08 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/02 21:30:33 by jocasado         ###   ########.fr       */
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
			return (cmd);
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
		temp = ft_strjoin(pipex->cmd_path[i], "/");
		f_path = ft_strjoin(temp, pipex->cmd_args[0]);
		free (temp);
		if (access(f_path, X_OK) == 0)
			return (f_path);
		free(f_path);
		i++;
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

void	full_free(t_pipex *pipex)
{
	ft_free2d(pipex->cmd_args);
	ft_free2d(pipex->cmd_path);
	free (pipex->cmd_fpath1);
	free (pipex->cmd_fpath2);
}
