#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t p1 = -1;
	p1  = fork();
	if (p1 == 0)
	{
		printf("child process. pid = %d.\n", getpid());
		
		printf("child process. pid = %d.\n", getppid());
	}

	if (p1 > 0)
	{
		printf("parent process. pid = %d.\n", getpid());
		
		printf("hello world. pid = %d.\n", p1);
	}
	printf("hello world.pid = %d.\n", p1);
	return 0;
}
