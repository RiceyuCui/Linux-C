#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int fd1 = -1, fd2 = -1;

	int ret = -1;
	char writebuf[20] = "abcd";
	char buf[100] = {0};
	
	 
	fd1 = open("a.txt", O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0666);
	fd2 = open("a.txt", O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0666);
	if( (fd1 == -1) || (fd2 == -1))
	{
		perror("file open error");
		_exit(-1);
	}
	
	
	#if 1

	while (1)
	{
	        ret = write(fd1, "ab",2);

		if (ret < 0)
		{
			printf("write error.\n");
			_exit(-1);
		}
		else
		{
			printf("fd1 write success. write %d chars.\n", ret);
		
		}
		sleep(1);

	        ret = write(fd2, "cd",2);

        	if (ret < 0)
        	{
                	printf("write error.\n");
                	_exit(-1);
        	}
       		 else
       		{
               		 printf("fd2 write success. write %d chars.\n", ret);
                
        	}

	}
	#endif

	#if 0

	while (1)
	{
		memset(buf, 0, sizeof(buf));
	        ret = read(fd1, buf, 2);
	
        	if ( (ret < 0) || (ret == 0))
       		{	
        	        printf("read error.\n");
               		 _exit(-1);
       		 }
       		 else
       		 {
               		 printf("fd1 read %d chars.\n", ret);
               		 printf("file contett:[ %s ]\n",buf);
       		 }
		
		sleep(1);
		
		memset(buf, 0, sizeof(buf));
                ret = read(fd2, buf, 2);

                if ( (ret < 0) || (ret == 0))
                {       
                        printf("read error.\n");
                         _exit(-1);
                 }
                 else
                 {
                         printf("fd2 read %d chars.\n", ret);
                         printf("file contett:[ %s ]\n",buf);
                 }

               
	}
	#endif

	close(fd1);
	close(fd2);
	return 0;
	//exit(0);
}
