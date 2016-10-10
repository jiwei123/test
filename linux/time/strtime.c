#define	_XOPEN_SOURCE

#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SBUF_SIZE	(1000)

int main(int argc, char *argv[])
{
	struct tm tm;
	char sbuf[SBUF_SIZE];
	char *ofmt;

	if ((argc < 3) || (strcmp(argv[1], "--help") == 0)) {
		printf("%s input-date-time in-format [out-format]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

#if 0
	if (setlocale(LC_ALL, "") == NULL) {
		printf("setlocal()\n");
		exit(EXIT_FAILURE);
	}
#endif

	memset(&tm, 0, sizeof(struct tm));
	if (strptime(argv[1], argv[2], &tm) == NULL) {
		printf("strptime()\n");
		exit(EXIT_FAILURE);
	}

	tm.tm_isdst = -1;

	printf("calendar time(seconds since Epoch): %ld\n", (long)mktime(&tm));

	ofmt = (argc > 3) ? argv[3] : "%H:%M:%S %A, %d %B %Y %Z";
	if (strftime(sbuf, SBUF_SIZE, ofmt, &tm) == 0) {
		printf("strftime()\n");
		exit(EXIT_FAILURE);
	}

	printf("strftime() yields: %s\n", sbuf);

	exit(EXIT_SUCCESS);
}
