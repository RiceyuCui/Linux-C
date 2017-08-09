#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int cal_len(const char *pathname)
{
	int fd = -1;
        int ret = -1;
	
	fd = open(pathname, O_RDONLY);

        if (-1 == fd)
        {
                perror("file open error.\n");
                return(-1);
        }

	ret = lseek(fd, 0, SEEK_END);

	return ret;
}
int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage : %s filename.\n", argv[0]);
		_exit(-1);
	}

	
	printf("file len: %d chars.\n", cal_len(argv[1]));

	return 0;
}

