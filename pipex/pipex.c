/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:23 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/31 14:13:11 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//checkear que se tienen los permisos adecuados para ambos fd.
//comprobar primero el fichero de salida para crearlo aunq haya fallo en el de entrada (permisos no existencia etc)
//funcion de error para cuando falle la apertura, en la que se abra el out aunq el in de error aka perror open exit -1;

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_argcerror();
	if (access(argv[1], R_OK) != 0)
		ft_error_infile(argv[4]);
	pipex.fd_out = open (argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (access(argv[4], W_OK) != 0)
		ft_serror();
	pipex.fd_in = open (argv[1], O_RDONLY);
	if (pipex.fd_in < 0 || pipex.fd_out < 0)
		return (-1);
	pipex.path = comm_path(envp);
	pipex.cmd_args = NULL;
	pipex.cmd_path = ft_split(pipex.path, ':'); //checkear si falla y liberar
	if (pipex.cmd_path == NULL)
		exit (1);
	pipex.cmd_fpath1 = cmd_found(&pipex, argv[2]);
	if (pipe(pipex.pipe) < 0)
		error_on_pipe(&pipex);
	first_child(&pipex);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	full_free(&pipex);
	exit(0);
}
