#include <stdio.h>
#include <sys/klog.h>
#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
	printf("My pid is %d.\n", getpid());
	
	openlog("a.out", LOG_PID|LOG_CONS, LOG_USER);
	
	
	 syslog(LOG_INFO, "This is my log info.");

	closelog();

	return 0;
}
