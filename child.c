#include "pipex.h"

char	*get_cmd_path(char *cmd, char **paths);

void	write_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.end[1],STDOUT_FILENO);
	close(pipex.end[0]);
	dup2(pipex.infd, STDIN_FILENO);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd_path(pipex.cmd_args[0], pipex.cmd_paths);
	if (pipex.cmd == NULL)
	{
		free_child(&pipex);
		exit_msg(ERRCMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	read_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.end[0],STDIN_FILENO);
	close(pipex.end[1]);
	dup2(pipex.outfd, STDOUT_FILENO);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd_path(pipex.cmd_args[0], pipex.cmd_paths);
	if (pipex.cmd == NULL)
	{
		free_child(&pipex);
		exit_msg(ERRCMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

/*
Finds the path that has the command from the argv argument
Parameter:
@cmd: command from argv argument
@paths: array of path names
Return: command path if any, else returns NULL
*/
char	*get_cmd_path(char *cmd, char **paths)
{
	char	*temp;
	char	*cmd_path;

	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, 0) == 0)
			return (cmd_path);
		free(cmd_path);
		paths++;
	}
	return (NULL);
}