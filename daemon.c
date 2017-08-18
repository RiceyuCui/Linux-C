#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
	creat_daemon();

	while(1)
	{
		printf("I am running!.\n");
	}

	return 0;

}

int creat_daemon()
{
	pid_t pid = 0;
	pid = fork();

	if (pid < 0)
	{
		perror("fork");
	}
	
	if (pid > 0)
	{
		exit(0);
	}

	 pid = setsid();
	if (pid < 0)
	{
		perror("setsid");
		exit(-1);
	}
	chdir("/");
	umask(0);

	int cnt = sysconf(_SC_OPEN_MAX);
	
	int i = 0;
	for (i = 0; i < cnt; i++)
	{
		close(i);
	}
	open("/dev/null", O_RDWR);
	open("/dev/null", O_RDWR);
	open("/dev/null", O_RDWR);
  	return 0;
}
