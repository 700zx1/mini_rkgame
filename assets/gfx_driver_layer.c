
// gfx_driver_layer.c - GFX abstraction layer using driver.so from SF3000
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>

static void *driver_handle = NULL;

// Function pointers from driver.so
static void (*fbdev_init)(void) = NULL;
static void (*fbdev_deinit)(void) = NULL;
static void (*fbdev_draw_frame)(const void *frame, int pitch) = NULL;
static void (*video_driver_get_size)(int *w, int *h) = NULL;

int gfx_driver_load(const char *path) {
    driver_handle = dlopen(path, RTLD_NOW);
    if (!driver_handle) {
        return -1;
    }

    fbdev_init = dlsym(driver_handle, "fbdev_init");
    fbdev_deinit = dlsym(driver_handle, "fbdev_deinit");
    fbdev_draw_frame = dlsym(driver_handle, "fbdev_draw_frame");
    video_driver_get_size = dlsym(driver_handle, "video_driver_get_size");

    if (!fbdev_init || !fbdev_deinit || !fbdev_draw_frame || !video_driver_get_size) {
        dlclose(driver_handle);
        return -2;
    }

    return 0;
}

void gfx_driver_init() {
    if (fbdev_init) fbdev_init();
}

void gfx_driver_shutdown() {
    if (fbdev_deinit) fbdev_deinit();
    if (driver_handle) {
        dlclose(driver_handle);
        driver_handle = NULL;
    }
}

void gfx_driver_draw(const void *frame, int pitch) {
    if (fbdev_draw_frame) fbdev_draw_frame(frame, pitch);
}

void gfx_driver_get_size(int *w, int *h) {
    if (video_driver_get_size) video_driver_get_size(w, h);
}
