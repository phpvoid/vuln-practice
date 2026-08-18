#include <stdio.h>

void test(char *fmt)
{
	//user input used directly as format string
	printf(fmt);
	printf("\n");
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
