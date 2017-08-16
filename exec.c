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
		printf("parent process. child pid = %d.\n", pid);
		
	}
	else if (pid == 0)
	{
		execl("/bin/ls", "ls", "-l", "-a", NULL);
		
		return 0;	
	}

	else
	{
		perror("fork");
		return -1;
	}

	return 0;
}
