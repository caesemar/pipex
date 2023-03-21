/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:49:45 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/21 19:33:17 by jocasado         ###   ########.fr       */
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
char	*cmd_path_finder(t_pipex pipex, char *cmd);
char	*cmd_found(t_pipex pipex, char *cmd);
char	*cmd_trim(char	*cmd);
void	pipexf(t_pipex pipex, char *comm1, char *comm2);
#endif