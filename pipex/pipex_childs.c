/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:47:43 by caesemar          #+#    #+#             */
/*   Updated: 2023/03/31 16:12:48 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *pipex, char *argv[])
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		error_on_pipe(&pipex);
	if (pipex->pid1 == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		dup2(pipex->pipe[1], STDOUT_FILENO);
		//close(pipex->fd_in);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		if (execve(pipex->cmd_fpath1, pipex->cmd_args, NULL) == -1)
			ft_serror();
	}
	second_child(&pipex, argv[3]);
}

void	second_child(t_pipex *pipex, char *argv[])
{
	pipex->cmd_fpath2 = cmd_found(&pipex, argv[3]);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error_on_pipe(&pipex);
	if (pipex->pid2 == 0)
	{
		dup2(pipex->pipe[0], STDIN_FILENO);
		dup2(pipex->pipe[1], pipex->fd_out);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		if (execve(pipex->cmd_fpath2, pipex->cmd_args, NULL) == -1)
			ft_serror();
	}
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}
