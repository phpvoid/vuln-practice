#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buf = malloc(32);

	if (!buf)
		return 1;

	printf("allocated at %p\n", (void *)buf);

	free(buf);
	//double free corrupts allocator metadata
	free(buf); 

	printf("end, heap corrupted\n");
	return 0;
}
