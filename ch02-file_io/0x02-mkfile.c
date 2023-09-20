#include <fcntl.h>

/**
 * mkfile - creates a file only if it doesn't exist
 * @filename: filename
 * @mode: acces mode permissions
 *
 * Return: file descriptor on success, -1 otherwise
 */
int mkfile(const char *filename, int mode)
{
	return (open(filename, O_CREAT | O_EXCL, mode));
}
