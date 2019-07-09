#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static const char usage[] = "Usage: %s [options...]\n"
			    "\n"
			    "  -h              Show help message and quit.\n";

int main(int argc, char **argv)
{
	int opt;
	int err = 0;

	while ((opt = getopt(argc, argv, "h")) != -1) {
		switch (opt) {
		case 'h':
			fprintf(stderr, usage, argv[0]);
			return EXIT_SUCCESS;
		case ':':
			fprintf(stderr, "Option -%c requires an operand\n",
				optopt);
			err++;
			break;
		case '?':
			err++;
			break;
		}
	}

	if (optind >= argc) {
		err++;
	}

	if (err) {
		fprintf(stderr, usage, argv[0]);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
