#include <stdio.h>

void test(char *fmt)
{
	int canary = 0x1337;

	printf("canary before: 0x%x\n", canary);

	//%n turns this into an arbitrary write primitive
	printf(fmt);

	printf("\ncanary after:  0x%x\n", canary);
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s <format-string>\n", argv[0]);
		return 1;
	}

	test(argv[1]);
	return 0;
}
