#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_LEN 1024
#define TIMEOUT 5

void perform_copy(int fd_in, int fd_out, fd_set *readfds, fd_set *writefds);

/**
 * main - testing out the select() function
 *
 * Return: 0
 */
int main(void)
{
	int fd_in, fd_out, select_return;
	fd_set readfds, writefds;
	struct timeval timeout;

	fd_in = open("README.md", O_RDONLY);
	if (fd_in == -1)
	{
		perror("open");
		return (1);
	}

	fd_out = open("copy_of_README.md", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		perror("open");
		return (1);
	}

	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_SET(fd_in, &readfds);
	FD_SET(fd_out, &writefds);

	timeout.tv_sec = TIMEOUT;

	select_return = select(fd_out + 1, &readfds, &writefds, NULL, &timeout);

	/* check if the operation was unsuccessful */
	if (select_return == -1)
	{
		perror("select");
		return (1);
	}
	/* check for timeouts */
	else if (!select_return)
		printf("Timeout reached: Nothing is available for I/O");
	else
		perform_copy(fd_in, fd_out, &readfds, &writefds);

	return (0);
}

/**
 * perform_copy - copies the content from fd_in to fd_out
 * @fd_in: the input file descriptor
 * @fd_out: the output file descriptor
 * @readfds: the file descriptor to watch for reading
 * @writefds: the file descriptor to warch for writing
 */
void perform_copy(int fd_in, int fd_out, fd_set *readfds, fd_set *writefds)
{
	int len;
	char buffer[BUF_LEN];

	/* check if the file is ready for reading */
	if (FD_ISSET(fd_in, readfds))
	{
		len = read(fd_in, buffer, BUF_LEN);
		if (len == -1)
		{
			perror("read");
			exit(1);
		}
		/*
		 * the file is available, check if it's possible to write the contents.
		 */
		if (len && FD_ISSET(fd_out, writefds))
		{
			len = write(fd_out, buffer, len);
			if (len == -1)
			{
				perror("write");
				exit(1);
			}
			else
			{
				printf("Contents copied successfully\n");
				exit(0);
			}
		}
	}
	else
	{
		fprintf(stderr, "The file could not be read.\n");
		exit(1);
	}
}
