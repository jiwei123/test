#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	unsigned int pid;

	pid = fork();
	if (pid == 0) {
		execl("./test", "./test", "1", NULL);
	} else if (pid < 0) {
		printf("fork process error\n");
	}

	sleep(20);

	while (wait(NULL) != -1) {
		continue;
	}

	if (errno != ECHILD) {
		printf("wait function error:%d\n", errno);
		return errno;
	}

	return 0;
}
