#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned int val;
	srand(time(NULL));
	val = rand() % 10 + 1;
	printf("test program:%d sleep:%d\n", getpid(), val);
	sleep(val);
	printf("test program\n");
	return 0;
}
