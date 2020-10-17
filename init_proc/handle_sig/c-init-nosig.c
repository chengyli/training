#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("Process is sleeping\n");
	while (1) {
		sleep(100);
	}

	return 0;
}
