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
	int i;
	int total;

	if (argc < 2) {
		total = 1;
	} else {
		total = atoi(argv[1]);
	}

	signal(SIGTERM, sig_handler);

	printf("To create %d processes\n", total);

	for (i = 0; i < total; i++) {
		pid_t pid = fork();

		if (pid == 0) {
			pid_t m_pid, p_pid;
			m_pid = getpid();
			p_pid = getppid();
			printf("Child => PPID: %d PID: %d\n", p_pid, m_pid);
			while (1) {
				sleep(100);
			}
			printf("Child process eixts\n");
			exit(EXIT_SUCCESS);
		} else if (pid > 0) {
			printf("Parent created child %d\n", i);
		} else {
			printf("Unable to create child process. %d\n", i);
			break;
		}
	}

	printf("Paraent is sleeping\n");
	while (1) {
		sleep(100);
	}

	return EXIT_SUCCESS;
}
