/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:24:40 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/01 02:57:27 by caesemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_serror_infile(const char *argv)
{
	int	tempfd;

	if (access(argv, F_OK) != 0)
		tempfd = open (argv, O_CREAT| O_RDWR | O_TRUNC, 0644);
	perror("Input file error");
	exit (1);
}

void	ft_serror(void)
{
	perror("Error");
	exit (1);
}

void	ft_argcerror(void)
{
	ft_putstr_fd("Wrong number of arguments, program exited\n", 2);
	exit (1);
}

void	error_on_pipe(t_pipex *pipex)
{
	ft_free2d(pipex->cmd_path);
	ft_free2d(pipex->cmd_args);
	free(pipex->cmd_fpath1);
	ft_serror();
}
