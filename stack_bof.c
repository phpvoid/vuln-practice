#include <stdio.h>
#include <string.h>

void test(char *input)
{
	char buf[64];

	//no bounds check
	strcpy(buf, input);
	printf("buf: %s\n", buf);
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s <string>\n", argv[0]);
		return 1;
	}

	test(argv[1]);
	return 0;
}
