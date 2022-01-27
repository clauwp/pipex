/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:31:46 by clau              #+#    #+#             */
/*   Updated: 2022/01/27 11:31:49 by clau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int msg(char *message)
{
	write(2, message, ft_strlen(message));
	return (1);
}

void	exit_msg(char *message)
{
	perror(message);
	exit(1);
}
