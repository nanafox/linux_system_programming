#include "io.h"
#define BUFFSIZE 1024

/**
 * main - testing read and pread
 *
 * Return: 0
 */
int main(void)
{
	int fd1, fd2;
	char fd1_buff[BUFFSIZE], fd2_buff[BUFFSIZE];
	char *filename = "io.h";

	fd1 = open(filename, O_RDONLY);
	check_fd(fd1, 0);

	fd2 = open(filename, O_RDONLY);
	check_fd(fd2, 0);

	/* check the current file position before perform read operation */
	printf("fd1 position before read: %ld\n", lseek(fd1, 0, SEEK_CUR));
	printf("fd2 position before pread: %ld\n\n", lseek(fd2, 0, SEEK_CUR));

	/* read operation */
	read(fd1, fd1_buff, BUFFSIZE);
	pread(fd2, fd2_buff, BUFFSIZE, 0);

	printf("fd1 position after read: %ld\n", lseek(fd1, 0, SEEK_CUR));
	printf("fd2 position after pread: %ld\n", lseek(fd2, 0, SEEK_CUR));

	printf("\nThe read() system call moves the file position, pread() does not\n");
	return (0);
}
