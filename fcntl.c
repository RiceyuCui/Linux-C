#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define FILENAME "a.txt"

int main(void)
{
	int fd1 = -1;
	int fd2 = -1;
	fd1 = open(FILENAME, O_RDWR);

	if (fd1 < 0)
	{
		perror("open");
		return -1;
	}
	printf("fd1 = %d.\n", fd1);

//	close (1);
	
	fd2 = fcntl(fd1, F_DUPFD, 0);
	printf("fd2 = %d.\n", fd2);






	close(fd1);
	return 0;
}

