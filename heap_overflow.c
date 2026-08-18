#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[16];
	void (*log_fn)(const char *);
} record_t;

void safe_log(const char *s)
{
	printf("log: %s\n", s);
}

int main(int argc, char **argv)
{
	record_t *rec;

	if (argc < 2) {
		fprintf(stderr, "usage: %s <name>\n", argv[0]);
		return 1;
	}

	rec = malloc(sizeof(record_t));
	if (!rec)
		return 1;

	rec->log_fn = safe_log;

	//overflow into log_fn adjacent in the same chunk
	strcpy(rec->name, argv[1]);

	//calls attacker-controlled pointer if overflowed
	rec->log_fn("hello");

	free(rec);
	return 0;
}
