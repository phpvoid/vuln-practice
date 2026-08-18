#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *buf = malloc(64);

	if (!buf)
		return 1;

	strcpy(buf, "hello heap");
	free(buf);

	//read after free
	printf("uaf read:  %s\n", buf);

	//write after free
	strcpy(buf, "corrupted after free");
	printf("uaf write: %s\n", buf);

	return 0;
}
