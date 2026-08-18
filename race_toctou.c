#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;

	if (argc < 2) {
		fprintf(stderr, "usage: %s <path>\n", argv[0]);
		return 1;
	}

	//time of check
	if (access(argv[1], W_OK) != 0) {
		perror("access");
		return 1;
	}

	sleep(2);

	//time of use
	fd = open(argv[1], O_WRONLY);
	if (fd < 0) {
		perror("open");
		return 1;
	}

	write(fd, "test\n", 5);
	close(fd);
	printf("wrote to %s\n", argv[1]);
	return 0;
}
