#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char user[8];
	char pad[8];
	int authenticated;
} session_t;

int main(void)
{
	char *secret;
	session_t *s;
	size_t i;

	secret = malloc(sizeof(session_t));
	strcpy(secret, "SECRET_KEY=secret");
	free(secret); //freed chunk likely goes to tcache

	//malloc does not zero memory
	s = malloc(sizeof(session_t));
	strncpy(s->user, "person", sizeof(s->user));

	printf("pad bytes (uninitialized, may be leaked heap data): ");
	for (i = 0; i < sizeof(s->pad); i++)
		putchar(s->pad[i] >= 32 && s->pad[i] < 127 ? s->pad[i] : '.');
	printf("\n");

	//	
	printf("authenticated flag (uninitialized): %d\n", s->authenticated);

	free(s);
	return 0;
}
