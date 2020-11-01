#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BLOCK_SIZE (1024*1024)

int main(int argc, char **argv)
{

	int thr, i;
	char *p1;

	if (argc != 2) {
		printf("Usage: mem_alloc <num (MB)>\n");
		exit(0);
	}

	thr = atoi(argv[1]);

	printf("Allocating," "set to %d Mbytes\n", thr);
	sleep(30);
	for (i = 0; i < thr; i++) {
		p1 = malloc(BLOCK_SIZE);
		memset(p1, 0x00, BLOCK_SIZE);
	}

	sleep(600);

	return 0;
}
