#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char cmd[256];

	if (argc < 2) {
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		return 1;
	}

	//
	////
	///
	snprintf(cmd, sizeof(cmd), "ls -l %s", argv[1]);
	system(cmd);
	return 0;
}
