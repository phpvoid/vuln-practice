#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("running backup helper via path-resolved 'tar'...\n");

	//trusts whatever $PATH resolves "tar" to
	system("tar --version");
	return 0;
}
