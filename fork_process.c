#include "shell.h"

/**
 * fork_process - executes arguments
 * @argv:array of arguments
 * @envp: environment variables
 *
 * Return: 0
 */

int fork_process(char **argv, char **envp)
{
	pid_t pid_of_child;
	int status;

	pid_of_child = fork();
	if (pid_of_child == -1)
	{
		perror("You don't have a child");
		return (1);
	}
	if (pid_of_child == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("./hsh: No such file or directory does not exist");
			return (1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
