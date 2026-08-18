#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	unsigned int count;
	size_t size;
	int *arr;
	unsigned int i;

	if (argc < 2) {
		fprintf(stderr, "usage: %s <count>\n", argv[0]);
		return 1;
	}

	count = (unsigned int)strtoul(argv[1], NULL, 10);

	//wraps for large count, undersized allocation follows
	size = count*sizeof(int);

	arr = malloc(size);
	if (!arr) {
		perror("malloc");
		return 1;
	}
	//
	// oob write once size has wrapped
	for (i = 0; i < count; i++)
		arr[i] = (int)i;

	printf("wrote %u ints into a buffer sized for %zu bytes\n", count, size);
	free(arr);
	return 0;
}
