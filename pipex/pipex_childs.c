/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caesemar <caesemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:47:43 by caesemar          #+#    #+#             */
/*   Updated: 2023/03/27 20:02:59 by caesemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void	childs(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		ft_serror();
	if (pipex->pid1 == 0)
	{
		dup2(pipex->pipe[1], pipex->pipe[0]);
		close(pipex->pipe[0]);
		execve(pipex->cmd_fpath1, pipex->cmd_args1, NULL);
	}

}
