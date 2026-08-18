#include <stdio.h>

int main(int argc, char **argv)
{
	char path[256];
	char line[256];
	FILE *f;

	if (argc < 2) {
		fprintf(stderr, "usage: %s <filename under ./data/>\n", argv[0]);
		return 1;
	}

	//no '..' check
	snprintf(path, sizeof(path), "./data/%s", argv[1]);

	f = fopen(path, "r");
	if (!f) {
		perror("fopen");
		return 1;
	}

	while (fgets(line, sizeof(line), f))
		fputs(line, stdout);

	fclose(f);
	return 0;
}
