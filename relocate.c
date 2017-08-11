#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define FILENAME "1.txt"

int main(void)
{
	int fd1 = -1;
	int fd2 = -1;
	fd1 = open(FILENAME, O_RDWR | O_CREAT | O_TRUNC, 0644);

	if (fd1 < 0)
	{
		perror("open");
		return -1;
	}

	printf("fd1 = %d.\n", fd1);
	close(1);
	
	fd2  = dup(fd1);
	printf("fd2 = %d.\n", fd2);
	printf("Test!");
	close(fd1);
		

	return 0;
}
