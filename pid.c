#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main (void)
{
	int fd = -1;
	int pid = -1;

	if (fd < 0)
	{
		perror("open");

	}
	pid = fork();
	if (pid > 0)
	{
		fd = open("1.txt", O_RDWR);
		printf("parent process.\n");
		write(fd, "hello", 5);
		sleep(1);
	}
	else if (pid == 0)
	{
		fd = open("1.txt", O_RDWR);
		printf("child process.\n");
		write(fd, "world", 5);
		sleep(1);

	}
	else
	{
		perror("fork");
		return -1;
	}
	
}
