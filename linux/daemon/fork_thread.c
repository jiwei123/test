#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

static void sig_handler(int sig)
{
	int pid;
	printf("signal:%d\n", sig);

#if 0
	while ((pid = wait(NULL)) != -1) {
		if (pid > 0) {
			printf("process(id:%d) exit\n", pid);
		}
		if (errno != ECHILD) {
			printf("wait function error:%d\n", errno);
		}
	}
#else
	pid = wait(NULL);
	if (pid > 0) {
		printf("process(id:%d) exit\n", pid);
	}
	if (errno != ECHILD) {
		printf("wait function error:%d\n", errno);
	}
#endif
}

int main(int argc, char *argv[])
{
	unsigned int pid;
	unsigned int i;

	if (signal(SIGCHLD, sig_handler) == SIG_ERR) {
		printf("signal error\n");
	}

	for (i = 0; i < 10; i++) {
		sleep(1);
		pid = fork();
		if (pid == 0) {
			setsid();
			execl("./test", "./test", "1", NULL);
		} else if (pid < 0) {
			printf("fork process error\n");
		}
	}

	printf("parent process wait\n");


	return 0;
}
