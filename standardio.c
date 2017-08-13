#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define FILENAME "1.txt"
int main(void)
{
	FILE *fp = NULL;
	size_t len = -1;
	int array[10] = {1, 2, 3, 4, 5};
	char buf[100] = {};
	fp  = fopen(FILENAME, "r+");

	if (NULL == fp)
	{
		perror("fopen");
		_exit(-1);
	}

	printf("fopen success. fp = %p.\n", fp);
	memset(buf, 0, sizeof(buf));
	len = fread(buf, 1, 10, fp);
	printf("len = %d.\n", len);

	printf("bus is : [%s].\n", buf);

	fclose(fp);









	return 0;
}
