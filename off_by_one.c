#include <stdio.h>
#include <string.h>

void copy_n(char *dst, const char *src, size_t n)
{
	size_t i;

	//should be i < n, this writes one byte too many
	for (i = 0; i <= n; i++)
		dst[i] = src[i];
}

int main(int argc, char **argv)
{
	char buf[16];

	if (argc < 2) {
		fprintf(stderr, "usage: %s <string up to 16 chars>\n", argv[0]);
		return 1;
	}

	memset(buf, 0, sizeof(buf));
	copy_n(buf, argv[1], sizeof(buf) - 1);

	printf("buf: %.16s\n", buf);
	return 0;
}
