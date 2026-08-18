#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE	64

int is_valid_length(int len)
{
	//negative len is true as well
	return len < MAX_SIZE;
}

void process(const char *data, int len)
{
	char buf[MAX_SIZE];

	if (!is_valid_length(len)) {
		fprintf(stderr, "rejected: length too large\n");
		return;
	}

	//negative len becomes a huge size t
	memcpy(buf, data, len);
	printf("processed %d bytes\n", len);
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "usage: %s <data> <len>\n", argv[0]);
		return 1;
	}

	process(argv[1], atoi(argv[2]));
	return 0;
}
