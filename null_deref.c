#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[32];
	int value;
} record_t;

record_t *find_record(int id)
{
	static record_t r = {"answer", 42};

	if (id != 42)
		return NULL;

	return &r;
}

int main(int argc, char **argv)
{
	int id = argc > 1 ? atoi(argv[1]) : 0;
	record_t *rec = find_record(id);

	//no null check
	printf("record: %s = %d\n", rec->name, rec->value);
	return 0;
}
