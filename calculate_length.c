#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main (int argc, char *argv[])
{
	int fd = -1;
	int ret = -1;
	if (argc != 2)
	{
		printf("usage : %s filename.\n", argv[0]);
		_exit(-1);
	}

	fd = open(argv[1], O_RDONLY);
	
	if (-1 == fd)
	{
		perror("file open error.\n");
		_exit(-1);
	}
	else
	{
		printf("file open success. fd = %d.\n", fd);
	}

	ret = lseek(fd, 0, SEEK_END);
	printf("file len: %d chars.\n", ret);

	return 0;
}

