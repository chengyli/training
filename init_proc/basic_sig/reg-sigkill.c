#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void sig_handler(int signo)
{
	if (signo == SIGKILL) {
		printf("received SIGKILL\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	sighandler_t h_ret;

	h_ret = signal(SIGKILL, sig_handler);
	if (h_ret == SIG_ERR) {
		perror("SIG_ERR");
	}

	return 0;
}
