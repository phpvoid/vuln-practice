#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_CAP	32

void handle_request(const char *payload, int claimed_len)
{
	char buf[BUF_CAP];
	char response[256];

	strncpy(buf, payload, BUF_CAP - 1);
	buf[BUF_CAP-1] = '\0';

	//claimed_len is attacker supplied, never checked against real size
	memcpy(response, buf, claimed_len);
	fwrite(response, 1, claimed_len, stdout);
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "usage: %s <payload> <claimed_len>\n", argv[0]);
		return 1;
	}

	handle_request(argv[1], atoi(argv[2]));
	return 0;
}
