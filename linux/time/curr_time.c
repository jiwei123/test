#include <time.h>

#define BUF_SIZE (1000)

char *currtime(const char *format)
{
	static char buf[BUF_SIZE];
	time_t t;
	size_t s;
	struct tm *tm;

	t = time(NULL);
	tm = localtime(&t);
	if (!tm) {
		printf("Error:localtime()\n");
		return NULL;
	}

	s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%c", tm);

	return (s == 0) ? NULL : buf;
}
