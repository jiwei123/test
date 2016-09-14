#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

static void sig_handler(int sig)
{
	int pid;
	printf("signal:%d\n", sig);

	pid = wait(NULL);
	if (pid > 0) {
		printf("process(id:%d) exit\n", pid);
	}

	if (errno != ECHILD) {
		printf("wait function error:%d\n", errno);
	}
}

int main(int argc, char *argv[])
{
	unsigned int pid;

	if (signal(SIGCHLD, sig_handler) == SIG_ERR) {
		printf("signal error\n");
	}

	pid = fork();
	if (pid == 0) {
		execl("./test", "./test", "1", NULL);
	} else if (pid < 0) {
		printf("fork process error\n");
	}

	sleep(20);
	printf("parent process exit\n");


	return 0;
}
