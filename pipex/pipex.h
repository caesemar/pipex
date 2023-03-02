/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:49:45 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/02 18:46:39 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
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
	char	**cmd_args;
}t_pipex;

void	pipexf(t_pipex pipex, char *comm1, char *comm2);
#endif