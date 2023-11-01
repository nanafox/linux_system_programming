#include <stdio.h>
#include <unistd.h>
#include <errno.h>

/**
 * main - executes a program
 * @argc: the argument counter
 * @argv: the argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char path[30];
	int retval;

	if (!(argc >= 2))
	{
		fprintf(stderr, "Usage: %s <program_name> [args...]\n", argv[0]);
		return (1);
	}

	argv[argc] = NULL; /* null terminate the array */
	sprintf(path, "/bin/%s", argv[1]); /* build up the absolute path */
	retval = execv(path, &argv[1]); /* execute the program */

	if (retval == -1)
	{
		perror("run");
		return (1); /* an error occured while trying to execute the program */
	}

	return (0);
}
