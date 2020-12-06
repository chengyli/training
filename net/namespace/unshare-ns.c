#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                               } while (0)

int main(void)
{
	pid_t pid;

	printf("Host Namespace Devices:\n");
	system("ip link");
	printf("\n\n");

	if (unshare(CLONE_NEWNET) == -1)
		errExit("unshare");

	printf("New Namespace Devices:\n");
	system("ip link");
	printf("\n\n");

	return 0;
}
