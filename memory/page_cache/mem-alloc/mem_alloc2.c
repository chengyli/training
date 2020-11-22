#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MB (1024*1024)

int main(int argc, char **argv)
{
	char *p;

	p = malloc(100 * MB);
	if (p == NULL)
		return 0;
	sleep(30);

	memset(p, 0x00, 20 * MB);

	sleep(1000);
	return 0;

}
