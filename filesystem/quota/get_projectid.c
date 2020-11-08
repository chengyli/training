#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <linux/quota.h>
#include <linux/dqblk_xfs.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	char *name;
	struct fsxattr fsxattr;

	if (argc != 2) {
		printf("Usage: get_projectid <dir_name>\n");
		exit(-1);
	}
	name = argv[1];

	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit(-1);

	ret = ioctl(fd, FS_IOC_FSGETXATTR, &fsxattr);
	if (ret < 0) {
		printf("ioctl eror\n");
		exit(-1);
	}

	close(fd);

	printf("Dir: %s projectid is %d\n", name, fsxattr.fsx_projid);
	return 0;

}
