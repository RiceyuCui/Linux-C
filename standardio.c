#include <stdio.h>
#include <unistd.h>

#define FILENAME "1.txt"
int main(void)
{
	FILE *fp = NULL;
	fp  = fopen(FILENAME, "w+");

	if (NULL == fp)
	{
		perror("fopen");
		_exit(-1);
	}

	printf("fopen success. fp = %p.\n", fp);

	fclose(fp);









	return 0;
}
