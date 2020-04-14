#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <wayland-client.h>

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

	if (err) {
		fprintf(stderr, usage, argv[0]);
		return EXIT_FAILURE;
	}

	struct wl_display *display = wl_display_connect(NULL);
	if (!display) {
		fprintf(stderr, "Failed to connect to Wayland display.\n");
		return EXIT_FAILURE;
	}

	while (wl_display_dispatch(display) != -1) {
		/* This space deliberately left blank */
	}

	wl_display_disconnect(display);

	return EXIT_SUCCESS;
}
