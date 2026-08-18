#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test(void)
{
	char *buf = malloc(1024 * 1024);
	//
	// never freed
	(void)buf;
}

int main(void)
{
	int i;

	for (i = 0; i < 100; i++) {
		test();
		printf("iteration %d\n", i);
		usleep(50000);
	}

	printf("done\n");
	return 0;
}
