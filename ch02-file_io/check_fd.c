#include "io.h"

/**
 * check_fd - exits if a file descriptor is invalid
 * @fd: file descriptor
 * @event: event that cause the error
 */
void check_fd(int fd, int event)
{
	char *events[] = {"open", "close", "read", "write"};

	if (fd == -1)
	{
		perror(events[event]);
		exit(1);
	}
}
