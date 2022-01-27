/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:32:04 by clau              #+#    #+#             */
/*   Updated: 2022/01/27 11:32:08 by clau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_child(t_pipex *pipex)
{
    int i;

    i = 0;
    while (pipex->cmd_args[i])
    {
        free(pipex->cmd_args[i]);
        i++;
    }
    free(pipex->cmd_args);
    free(pipex->cmd);
}

void    free_parent(t_pipex *pipex)
{
    int i;

    i = 0;
    while (pipex->cmd_paths[i])
    {
        free(pipex->cmd_paths[i]);
        i++;
    }
    free(pipex->cmd_paths);
}
