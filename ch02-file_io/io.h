#ifndef __IO_H__
#define __IO_H__

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int _creat(const char *, int);
int mkfile(const char *, int);
void check_fd(int fd, int event);

#endif
