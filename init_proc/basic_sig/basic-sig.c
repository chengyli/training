#include <stdio.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void sig_handler(int signo)
{
	if (signo == SIGTERM) {
		printf("received SIGTERM\n\n");
		// Set SIGTERM handler to default
		signal(SIGTERM, SIG_DFL);
	}
}

int main(int argc, char *argv[])
{
	//Ignore SIGTERM, and send SIGTERM 
	// to process itself.
	signal(SIGTERM, SIG_IGN);
	printf("Ignore SIGTERM\n\n");
	kill(0, SIGTERM);

	//Catch SIGERM, and send SIGTERM 
	// to process itself.
	signal(SIGTERM, sig_handler);
	printf("Catch SIGTERM\n");
	kill(0, SIGTERM);

	//Default SIGTERM. In sig_handler, it sets 
	//SIGTERM handler back to default one.
	printf("Default SIGTERM\n");
	kill(0, SIGTERM);

	return 0;
}
