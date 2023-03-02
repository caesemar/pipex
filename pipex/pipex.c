/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:23 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/02 19:08:03 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		c_f1;

	if (argc != 5)
		return (-1); //msgerror
	pipex.fd_in = open (argv[1], O_RDONLY);
	pipex.fd_out = open (argv[4], O_CREAT, O_RDWR, O_TRUNC, 0644);
	if (pipex.fd_in < 0 || pipex.fd_out < 0)
		return (-1); //errmsg
	if (pipe(pipex.pipe) < 0)
		return (-1); //errmsg
	pipex.path = comm_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');

	pipexf(pipex, comm1, comm2);
	return (0);
}

char	*comm_path(char	**envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

void	pipexf(t_pipex pipex, char *comm1, char *comm2)
{

}
