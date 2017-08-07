#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int fd = -1;
	int ret = -1;
	char writebuf[20] = "IloveLinux";
	char buf[100] = {0};
	
	 
	fd = open("a.txt", O_RDWR | O_TRUNC);
	if (fd == -1)
	{
		printf("file open error.\n");
	}
	else
	{
		printf("file open success.\n");
	}

	#if 1
        ret = write(fd, writebuf, strlen(writebuf));

	if (ret < 0)
	{
		printf("write error.\n");
	}
	else
	{
		printf("write success. write %d chars.\n", ret);
		
	}
	#endif

	#if 0
	ret = read(fd, buf, 20);
	
	if (ret < 0)
	{
		printf("read error.\n");
	}
	else
	{
		printf("read %d chars.\n", ret);
		printf("file contett:[ %s ]\n",buf);
	}
	#endif

	close(fd);
	return 0;
}
