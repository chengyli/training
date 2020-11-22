#include <fcntl.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include <stdlib.h> 

#define BUFFER_SIZE (1024 * 1024)
#define BLOCKS	800

char buf[BUFFER_SIZE];

int main(int argc, char *argv[])
{
	int fd;
	int i, ret = 0;
	char *p1;
	int blocks;

	if (argc != 3) {
		printf("Usage: read_file <filename> <blocks>");
		exit(0);
	}

	blocks = atoi(argv[2]);	

	fd = open(argv[1], O_RDONLY);
	while (1) {
		for (i = 0; i < blocks; i++) {
			ret = read(fd, buf, BUFFER_SIZE);
			if (ret < 0)
				printf("%d read error \n", i);
		}
		sleep(2);
		printf("Read again\n");
	}
	close(fd);
		
	return 0;
}
