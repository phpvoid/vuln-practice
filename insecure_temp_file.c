#include <stdio.h>

int main(void)
{
	char *tmpname;
	FILE *f;

	//predictable name, no atomicity between name and open
	tmpname = tmpnam(NULL);
	if (!tmpname) {
		fprintf(stderr, "tmpnam failed\n");
		return 1;
	}

	printf("using temp file: %s\n", tmpname);
	//
 	//race window, could follow a symlink
	f = fopen(tmpname, "w");
	if (!f) {
		perror("fopen");
		return 1;
	}

	fprintf(f, "scratch data\n");
	fclose(f);
	printf("wrote temp file\n");
	return 0;
}
