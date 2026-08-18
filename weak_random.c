#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int token;

	//~86400 values
	srand((unsigned int)time(NULL));
	token = rand() % 1000000;

	printf("session token: %06d\n", token);
	return 0;
}
