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
	char writebuf[20] = "abcd";
	char buf[100] = {0};
	
	 
	fd = open("123.txt", O_RDWR | O_CREAT, 0666);
	if (fd == -1)
	{
		perror("file open error");
		_exit(-1);
	}
	else
	{
		printf("file open success.\n");
	}
	
	
	ret = lseek(fd, 10, SEEK_SET);
	printf("lseek, ret = %d.\n", ret);
	#if 1
        ret = write(fd, writebuf, strlen(writebuf));

	if (ret < 0)
	{
		printf("write error.\n");
		_exit(-1);
	}
	else
	{
		printf("write success. write %d chars.\n", ret);
		
	}
	#endif

	#if 1
	ret = read(fd, buf, 20);
	
	if (ret < 0)
	{
		printf("read error.\n");
		_exit(-1);
	}
	else
	{
		printf("read %d chars.\n", ret);
		printf("file contett:[ %s ]\n",buf);
	}
	#endif

	close(fd);
	return 0;
	//exit(0);
}
