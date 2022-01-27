#include "pipex.h"

char	**get_paths(char **envp);

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex pipex;

	if (argc != 5)
		return (msg(ERRNO));
	pipex.infd = open(argv[1], O_RDONLY);
	if (pipex.infd < 0)
		exit_msg(ERRIN);
	pipex.outfd = open(argv[4], O_CREAT | O_RDWR);
	if (pipex.outfd < 0)
		exit_msg(ERROUT);
	if (pipe(pipex.end) < 0)
		exit_msg(ERRPIPE);
	pipex.cmd_paths = get_paths(envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		read_child(pipex,argv,envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		write_child(pipex,argv,envp);
	close(pipex.end[0]);
	close(pipex.end[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}

/*
To find "PATH" environment variable from envp argument passed in from main function
and split it with delimeter ':' to obtain an array of strings containing path names
Parameter:
@envp: array of environment variable
Return: array of path names
*/
char	**get_paths(char **envp)
{
	const char	*to_find;
	char		*path_var;

	to_find = "PATH";
	while (ft_strncmp(to_find, *envp, ft_strlen(to_find)))
		envp++;
	path_var = *envp + 5;
	return (ft_split(path_var, ':'));
}