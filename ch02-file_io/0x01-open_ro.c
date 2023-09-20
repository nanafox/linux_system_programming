#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#define BUFFSIZE 1000000

/**
 * main - write the contents of a file to stdout
 * @argc: cli args counter
 * @argv: filename
 *
 * Return: 0 on success, non-zero otherwise.
 */
int main(int argc, char *argv[])
{
	int fd;
	char buff[BUFFSIZE];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return (1);
	}

	while (read(fd, buff, BUFFSIZE))
	{
		buff[BUFFSIZE] = '\0';
		printf("%s\n", buff);
	}

	close(fd);
	return (0);
}
