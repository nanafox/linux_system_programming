#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - prints the PID and PPID
 *
 * Return: 0
 */
int main(void)
{
	pid_t pid = getpid();
	pid_t ppid = getppid();

	printf("pid: %d, ppid: %d\n", pid, ppid);

	/*
	 * Observations
	 *
	 * The pid (child's PID) keeps changing on each run but the PPID
	 * (parent's PID) remains the same on every call.
	 *
	 * This is because Linux doesn't reuse PIDs until the value in
	 * /proc/sys/kernel/pid_max is allocated
	 */

	return (0);
}
