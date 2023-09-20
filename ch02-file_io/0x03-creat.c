#include <fcntl.h>

/**
 * _creat - creates a new file
 * @filename: filename
 * @mode: access mode permission
 *
 * Return: file descriptor on success, -1 otherwise
 */
int _creat(const char *filename, int mode)
{
	return (open(filename, O_CREAT | O_TRUNC | O_WRONLY, mode));
}
