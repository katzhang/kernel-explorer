#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define TTY_PATH "/dev/tty"

#define BUFFERSIZE 4096
#define COPYMODE 0644

void oops(char *, char *);

void copy(int in_fd, int out_fd) {
	int n_chars;
	char buf[BUFFERSIZE];

	while ((n_chars=read(in_fd, buf, BUFFERSIZE)) > 0) {
		if (write(out_fd, buf, n_chars) != n_chars) {
			oops("Write error to ", "");
		}
	}

	if (n_chars == -1) {
		oops("Read error from ", "");
	}

	if (close(in_fd) == -1 || close(out_fd) == -1) {
		oops("Error closing files", "");
	}
}

void oops(char *s1, char *s2) {
	fprintf(stderr, "Error: %s ", s1);
	perror(s2);
	exit(1);
}

int main(int ac, char *av[]) {
	int in_fd, out_tty, n_chars;
	char buf[BUFFERSIZE];

	if (ac != 2) {
		fprintf(stderr, "usage: %s source \n", *av);
		exit(1);
	}

	if ((in_fd=open(av[1], O_RDONLY)) == -1) {
		oops("Cannot open ", av[1]);
	}

	if ((out_tty=creat(TTY_PATH, COPYMODE)) == -1) {
		oops("Cannot creat", av[2]);
	}

	copy(in_fd, out_tty);
	return 0;
}
