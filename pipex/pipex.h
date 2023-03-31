/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:49:45 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/31 16:44:01 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;
	int		pipe[2];
	char	*path;
	char	**cmd_path;
	char	*cmd;
	char	*cmd_fpath1;
	char	*cmd_fpath2;
	char	**cmd_args;
}t_pipex;

char	*comm_path(char	**envp);
char	*cmd_path_finder(t_pipex *pipex, char *cmd);
char	*cmd_found(t_pipex *pipex, char *cmd);
void	ft_free2d(char	**tofree);
void	error_on_pipe(t_pipex *pipex);
void	full_free(t_pipex *pipex);
void	first_child(t_pipex *pipex, char *argv[]);
void	second_child(t_pipex *pipex, char *argv[]);
void	ft_argcerror(void);
void	ft_serror(void);
void	ft_serror_infile(const char *argv);
#endif