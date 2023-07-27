#include "shell.h"

/**
 *   * main - entry point for codes
 *     * @argc: number of arguments
 *       * @argv: array of arguments
 *         * @envp: environment variables
 *           * Return: 0 for success
 */

int main(int argc, char *argv[], char *envp[])
{
	size_t n = 10;
	char exit_program[5] = "exit", environ[5] = "env", path[10] = "/bin/";
	char *string_input = NULL;
	char *agv[15];
	ssize_t num_of_chars;
	int i, j, k;
	(void) argc;
	(void) argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		num_of_chars = getline(&string_input, &n, stdin);
		if (num_of_chars == -1)
		{
			free(string_input);
			exit(0);
		}
		for (i = 0; string_input[i]; i++)
		{
			if (string_input[i] == '\n')
			string_input[i] = '\0';
		}
		k = 0;
		agv[k] = strtok(string_input, " ");
		while (agv[k])
		{
			k++;
			agv[k] = strtok(NULL, " ");
		}
		if (strcmp("ls", agv[0]) == 0)
		{
			strcat(path, agv[0]);
			agv[0] = path;
		}
		if (strcmp(exit_program, agv[0]) == 0)
		{
			free(string_input);
			exit(0);
		}
		j = 0;
		if (strcmp(environ, agv[0]) == 0)
		{
			while (envp[j] != NULL)
			{
				printf("%s\n", envp[j]);
				j++;
			}
		}
		fork_process(agv, envp);
	}
	free(string_input);
	free(agv);
	return(0);
}
