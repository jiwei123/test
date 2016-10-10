#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("current task user id:%d, group id:%d\n", getuid(), getgid());
	printf("euid:%d, egid:%d\n", geteuid(), getegid());
	return 0;
}
