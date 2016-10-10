#include <stdio.h>
#include <unistd.h>

#define UID	(2000)
void setuid_test()
{
	printf("Now test setuid\n");
	printf("Before modified\n");
	printf("uid:%d, gid:%d,", getuid(), getgid());
	printf("euid:%d, egid:%d\n", geteuid(), getegid());
	if (setuid(UID)) {
			printf("modify uid to %d error\n", UID);
		if (setuid(geteuid())) {
			printf("modify error\n");
		} else {
			printf("After modified\n");
			printf("uid:%d, gid:%d,", getuid(), getgid());
			printf("euid:%d, egid:%d\n", geteuid(), getegid());
		}
	} else {
		printf("After modified\n");
		printf("uid:%d, gid:%d,", getuid(), getgid());
		printf("euid:%d, egid:%d\n", geteuid(), getegid());
	}
	printf("Test setuid over\n");
}

void seteuid_test()
{
	printf("Now test seteuid\n");
	printf("Before modified\n");
	printf("uid:%d, gid:%d,", getuid(), getgid());
	printf("euid:%d, egid:%d\n", geteuid(), getegid());
	if (seteuid(UID)) {
			printf("modify euid to %d error\n", UID);
		if (seteuid(geteuid())) {
			printf("modify error\n");
		} else {
			printf("After modified\n");
			printf("uid:%d, gid:%d,", getuid(), getgid());
			printf("euid:%d, egid:%d\n", geteuid(), getegid());
		}
	} else {
		printf("After modified\n");
		printf("uid:%d, gid:%d,", getuid(), getgid());
		printf("euid:%d, egid:%d\n", geteuid(), getegid());
	}
	printf("Test seteuid over\n");
}

void setreuid_test()
{
	printf("Now test setreuid\n");
	printf("Before modified\n");
	printf("uid:%d, gid:%d,", getuid(), getgid());
	printf("euid:%d, egid:%d\n", geteuid(), getegid());
	if (setreuid(-1, UID + 1)) {
		printf("modify euid to %d error\n", UID);
	} else {
		printf("After modified\n");
		printf("uid:%d, gid:%d,", getuid(), getgid());
		printf("euid:%d, egid:%d\n", geteuid(), getegid());
	}
	printf("Test setreuid over\n");
}
int main()
{
	setreuid_test();
	return 0;
}
