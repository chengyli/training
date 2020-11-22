#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BLOCK_SIZE (1024*1024)

int main(int argc, char **argv)
{

	int thr, i;
	char *p1, *p2;

	if (argc != 2) {
		printf("Usage: mem_alloc <num (MB)>\n");
		exit(0);
	}

	thr = atoi(argv[1]);

	printf("Allocating," "set to %d Mbytes\n", thr);
	sleep(30);
	for (i = 0; i < (thr - 2); i++) {
		p1 = malloc(BLOCK_SIZE);
		memset(p1, 0x00, BLOCK_SIZE);
	}

	while (1) {
		p1 = malloc(BLOCK_SIZE);
		memset(p1, 0x00, BLOCK_SIZE);

		p2 = malloc(BLOCK_SIZE);
		memset(p2, 0x00, BLOCK_SIZE);

		sleep(1);

		free(p1);
		free(p2);

		sleep(2);
	}

	return 0;
}
