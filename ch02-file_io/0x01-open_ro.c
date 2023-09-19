#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#define BUFFSIZE 102400


/**
 * main - reading from files
 *
 * Return: 0
 */
int main(void)
{
	int fd;
	char buff[BUFFSIZE];

	fd = open("README.md", O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return (1);
	}

	while (read(fd, buff, BUFFSIZE))
		;
	printf("%s", buff);

	close(fd);
	return (0);
}
