/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:23 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/21 19:33:14 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		c_f1;

	if (argc != 5)
		return (-1); //msgerror
	//checkear que se tienen los permisos adecuados para ambos fd.
	//comprobar primero el fichero de salida para crearlo aunq haya fallo en el de entrada (permisos no existencia etc)
	pipex.fd_out = open (argv[4], O_CREAT, O_RDWR, O_TRUNC, 0644);
	if (access(argv[4], F_OK & W_OK & R_OK) != 0)
		return (-1);
	if (access(argv[1], F_OK & R_OK) != 0)
		return (-1);
	pipex.fd_in = open (argv[1], O_RDONLY);
	if (pipex.fd_in < 0 || pipex.fd_out < 0)
		return (-1); //errmsg
	pipex.path = comm_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');
	pipex.cmd_fpath1 = cmd_found(pipex, argv[2]);
	pipex.cmd_fpath2 = cmd_found(pipex, argv[3]);
	// if (pipex.cmd_fpath1 == NULL || pipex.cmd_fpath2 == NULL)
	// 	return (-1);//cmd not found
	if (pipe(pipex.pipe) < 0)
		return (-1); //errmsg
	pipexf(pipex, comm1, comm2);
	return (0);
}
