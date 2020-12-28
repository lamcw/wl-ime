#ifndef _WLIME_H
#define _WLIME_H

#include <wayland-client.h>

struct wlime {
	struct wl_display *wl_display;
	struct wl_registry *wl_registry;
};

#endif
