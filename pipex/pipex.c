/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:23 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/03 19:28:48 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_argcerror();
	if (access(argv[1], R_OK) != 0)
		ft_serror_infile(argv[4]);
	pipex.fd_out = open (argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (access(argv[4], W_OK) != 0)
		ft_serror();
	pipex.fd_in = open (argv[1], O_RDONLY);
	if (pipex.fd_in < 0 || pipex.fd_out < 0)
		ft_serror();
	pipex.path = comm_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');
	if (pipex.cmd_path == NULL)
		exit (1);
	pipex.cmd_args = NULL;
	pipex.cmd_fpath1 = cmd_found(&pipex, argv[2]);
	if (pipe(pipex.pipe) < 0)
		error_on_pipe(&pipex);
	first_child(&pipex, argv);
	full_free(&pipex);
	exit(0);
}

void	full_free(t_pipex *pipex)
{
	ft_free2d(pipex->cmd_args);
	ft_free2d(pipex->cmd_path);
	if (pipex->inputype == 1)
		free (pipex->cmd_fpath1);
	if (pipex->inputype == 2)
		free (pipex->cmd_fpath2);
}
