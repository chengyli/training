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

#define STACK_SIZE (1024 * 1024)
static char stack[STACK_SIZE];

int new_netns(void *para)
{
	printf("New Namespace Devices:\n");
	system("ip link");
	printf("\n\n");

	sleep(100);
	return 0;
}

int main(void)
{
	pid_t pid;

	printf("Host Namespace Devices:\n");
	system("ip link");
	printf("\n\n");

	pid =
	    clone(new_netns, stack + STACK_SIZE, CLONE_NEWNET | SIGCHLD, NULL);
	if (pid == -1)
		errExit("clone");

	if (waitpid(pid, NULL, 0) == -1)
		errExit("waitpid");

	return 0;
}
