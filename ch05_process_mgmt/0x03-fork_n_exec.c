#include <stdio.h>
#include <unistd.h>
#include <errno.h>

/**
 * main - executes a program
 * @argc: the argument counter
 * @argv: the argument vector
 *
 * Description: This program spawns a new process (child process) and runs
 * whatever command the shell gives on the command line if it's a valid command
 * else it fails. The command can take any number of arguments so long as it's
 * valid with the command being executed.
 *
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char *argv[])
{
	char path[30];
	int retval;
	pid_t pid;

	if (!(argc >= 2))
	{
		fprintf(stderr, "Usage: %s <program_name> [args...]\n", argv[0]);
		return (-1);
	}

	pid = fork(); /* create a child process */
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	/* ensure we are in the child process */
	if (!pid)
	{
		sprintf(path, "/bin/%s", argv[1]); /* build up the absolute path */
		retval = execve(path, &argv[1], NULL); /* execute the program */

		if (retval == -1)
		{
			perror("execve");
			return (-1); /* an error occured while trying to execute the program */
		}
	}

	return (0);
}
