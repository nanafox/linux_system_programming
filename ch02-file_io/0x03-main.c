#include <stdio.h>
#include "io.h"

/**
 * main - create new files
 * @argc: cli arg counter
 * @argv: list of filenames
 *
 * Description: Creates new files everytime it is executed. Existing files
 * are truncated to length 0 (overwritten). Files are created with the
 * permission 644 by default.
 *
 * Return: 0 on success, non-zero otherwise
 */
int main(int argc, char *argv[])
{
	int fd, i;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename...\n", argv[0]);
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		/* open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644) */
		fd = _creat(argv[i], 0644);
		if (fd == -1)
			perror("creat"); /* file creation failed */
	}

	return (0);
}
