#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	pid_t pid = -1;
	pid_t ret = -1;
	int status = -1;

	pid = fork();
	if (pid > 0)
	{
		printf("parent.\n");
		ret = wait(&status);
		printf("child process is recycled.child process pid = %d.\n", ret);
		
	}
	else if (pid == 0)
	{
		printf("child.pid = %d.\n", getpid());
		printf("if child process exit:%d.\n", WIFEXITED(status));
	}
	else
	{
		perror("fork");
		return -1;
	}

	return 0;
}
