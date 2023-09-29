#include <stdio.h>
#include "io.h"

/**
 * main - Creates a file only when it doesn't exist.
 * @argc: cli argument counter
 * @argv: filename
 *
 * Return: 0 on success, non-zero otherwise
 */
int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return (1);
	}
	fd = mkfile(argv[1], 0644);

	if (fd == -1)
	{
		perror("mkfile");
		return (1);
	}
	printf("Success: File creation successful\n");
	return (0);
}
