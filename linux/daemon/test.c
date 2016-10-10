#include <stdio.h>
//#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;
	unsigned int val;
	switch (fork()) {
	case -1: return -1;
	case 0: break;
	default: exit(EXIT_SUCCESS);
	}


	srand(time(NULL));
	val = rand() % 10 + 1;
	printf("test program:%d sleep:%d\n", getpid(), val);
	sleep(val);
	sleep(~0);
	printf("test program\n");
	return 0;
}
