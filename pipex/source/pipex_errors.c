/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:24:40 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/10 20:49:31 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_serror_infile(char **argv)
{
	if (access(argv[4], F_OK) != 0)
		open (argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (access(argv[4], W_OK) == 0)
		open(argv[4], O_TRUNC);
	perror(argv[1]);
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

void	ft_execverror(char	*s, t_pipex *pipex)
{
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd(": command not found \n", STDERR_FILENO);
	full_free(pipex, 0);
	exit (1);
}

void	error_on_pipe(t_pipex *pipex, int status)
{
	ft_free2d(pipex->cmd_path);
	ft_free2d(pipex->cmd_args);
	if (status == 1)
		free(pipex->cmd_fpath1);
	else
	{
		free(pipex->cmd_fpath1);
		free(pipex->cmd_fpath2);
	}
	ft_serror();
}
