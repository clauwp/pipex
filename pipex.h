#ifndef PIPEX_H
# define PIPEX_H

/* write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*perror*/
# include <stdio.h>

/* ft_split, ft_strjoin, ft_strncmp, ft_strlen*/
# include "functions/functions.h"

# define ERRNO "Invalid number of arguments"
# define ERRIN "Infile error"
# define ERROUT "Outfile error"
# define ERRPIPE "Pipe error"
# define ERRCMD "Command path not found"

typedef struct s_pipex{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
	int		infd;
	int		outfd;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

void	read_child(t_pipex pipex, char *argv[], char *envp[]);
void	write_child(t_pipex pipex, char *argv[], char *envp[]);

void	exit_msg(char *message);
int 	msg(char *message);

void    free_child(t_pipex *pipex);
void    free_parent(t_pipex *pipex);

#endif