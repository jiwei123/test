#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main()
{
	unsigned int i;
	unsigned char *mem = NULL;
	unsigned int size = 0;

#if 0
	for (i = 1024 * 10 + 900;; i++) {
		size = 1024 * i;
	printf("size is %d\n", size);
		mem = malloc(size);
		if (mem) {
			memset(mem, 0x5a, size);
#if 0
			for (i = 0; i < size; i++) {
				if (mem[i] != 0xa5) {
					break;
				}
			}
#endif
			free(mem);
		} else {
			size = 1024 * (i - 1);
			break;
		}
	}
#endif
	size = 1024 * (1024 * 10 + 500);
//	printf("size is %d\n", size);

	while (1) {
		mem = malloc(size);
		if (mem) {
			memset(mem, 0x5a, size);
			for (i = 0; i < size; i++) {
				if (mem[i] != 0x5a) {
					printf("==========error:memory is not 0x5a\n");
					return 1;
				}
			}
			memset(mem, 0xa5, size);
			for (i = 0; i < size; i++) {
				if (mem[i] != 0xa5) {
					printf("==========error:memory is not 0xa5\n");
					return 1;
				}
			}
		}
		free(mem);
	}

	return 0;
}
