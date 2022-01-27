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