/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:23 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/10 03:13:32 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
		error_on_pipe(&pipex, 1);
	first_child(&pipex, argv);
	full_free(&pipex, 0);
	exit(0);
}

void	full_free(t_pipex *pipex, int status)
{
	ft_free2d(pipex->cmd_args);
	ft_free2d(pipex->cmd_path);
	if (status == 1 || status == 0)
		free (pipex->cmd_fpath1);
	if (status == 2 || status == 0)
		free (pipex->cmd_fpath2);
}

void	ft_argtrim(t_pipex *pipex)
{
	int		i;
	char	*temp;
	size_t	secondf;

	secondf = 0;
	i = -1;
	while (pipex->cmd_args[++i] != NULL)
	{
		if (pipex->cmd_args[i][0] == '\'')
		{
			temp = ft_strdup(pipex->cmd_args[i]);
			ft_argtrim2(temp, &secondf);
			if (secondf % 2 == 0)
			{
				free(pipex->cmd_args[i]);
				pipex->cmd_args[i] = ft_strdup(temp);
			}
			free (temp);
		}
	}
}

void	ft_argtrim2(char *temp, size_t *secondf)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (temp[j] != 0)
	{
		if (temp[j] == '\'')
		{
			*secondf = *secondf + 1;
			j++;
		}
		temp[k++] = temp[j];
		if (temp [j] != 0)
			j++;
	}
	temp[j] = 0;
}

void	ft_execverror1(char	*s, t_pipex *pipex)
{
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd(": command not found \n", STDERR_FILENO);
	full_free(pipex, 1);
	exit (1);
}
