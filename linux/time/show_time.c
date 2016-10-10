#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE	(200)

int main(int argc, char *argv[])
{
	time_t t;
	struct tm * loc;
	char buf[BUF_SIZE];
#if 1

	if (setlocale(LC_ALL, "") == NULL) {
		printf("setlocale()\n");
		exit(EXIT_FAILURE);
	}
#endif

	t = time(NULL);
	printf("ctime() of time() value is %s", ctime(&t));

	loc = localtime(&t);
	if (!loc) {
		printf("localtime()\n");
		exit(EXIT_FAILURE);
	}

	printf("asctime() of local time is: %s", asctime(loc));

	if (strftime(buf, BUF_SIZE, "%A, %d %B %Y, %H:%M:%S %Z", loc) == 0) {
		printf("strftime()\n");
		exit(EXIT_FAILURE);
	}

	printf("strftime() of local time is:%s\n", buf);

	exit(EXIT_SUCCESS);
}
