/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caesemar <caesemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:23 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/27 20:05:05 by caesemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//checkear que se tienen los permisos adecuados para ambos fd.
//comprobar primero el fichero de salida para crearlo aunq haya fallo en el de entrada (permisos no existencia etc)
//funcion de error para cuando falle la apertura, en la que se abra el out aunq el in de error aka perror open exit -1;

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		c_f1;

	if (argc != 5)
		ft_argcerror();
	if (access(argv[1], F_OK | R_OK) != 0)
		ft_error_infile(argv[4]);
	pipex.fd_out = open (argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (access(argv[4], F_OK | W_OK) != 0)
		ft_serror();
	pipex.fd_in = open (argv[1], O_RDONLY);
	if (pipex.fd_in < 0 || pipex.fd_out < 0)
		return (-1);
	pipex.path = comm_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');
	pipex.cmd_fpath1 = cmd_found(&pipex, argv[2]);
	pipex.cmd_fpath2 = cmd_found(&pipex, argv[3]);
	if (pipe(pipex.pipe) < 0)
		ft_serror();
	pipex.pid2 = fork();
	child(&pipex);
	return (0);
}


