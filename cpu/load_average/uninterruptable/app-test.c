#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(void)
{
	char buf[100];
	int fd = open("/proc/mydev", O_RDWR);
	
	read(fd, buf, 1);

	write(fd, buf, 1);
}
