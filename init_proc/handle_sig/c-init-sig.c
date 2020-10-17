#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void sig_handler(int signo)
{
	if (signo == SIGTERM) {
		printf("received SIGTERM\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{

	signal(SIGTERM, sig_handler);

	printf("Process is sleeping\n");
	while (1) {
		sleep(100);
	}

	return 0;
}
