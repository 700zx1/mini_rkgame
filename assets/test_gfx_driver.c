
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "gfx_driver_layer.h"

#define WIDTH 640
#define HEIGHT 480

int main(void) {
    if (gfx_driver_load("driver.so") != 0) {
        fprintf(stderr, "[ERROR] Failed to load driver.so\n");
        return 1;
    }

    gfx_driver_init();

    int w = 0, h = 0;
    gfx_driver_get_size(&w, &h);
    if (w == 0 || h == 0) {
        w = WIDTH;
        h = HEIGHT;
    }

    uint16_t *frame = (uint16_t *)malloc(w * h * sizeof(uint16_t));
    if (!frame) {
        fprintf(stderr, "[ERROR] Failed to allocate frame buffer\n");
        gfx_driver_shutdown();
        return 1;
    }

    // Draw horizontal color bars
    uint16_t colors[] = {
        0xF800, // Red
        0x07E0, // Green
        0x001F, // Blue
        0xFFE0, // Yellow
        0x07FF, // Cyan
        0xF81F, // Magenta
        0xFFFF, // White
        0x0000  // Black
    };
    int bar_height = h / 8;
    for (int y = 0; y < h; y++) {
        uint16_t color = colors[(y / bar_height) % 8];
        for (int x = 0; x < w; x++) {
            frame[y * w + x] = color;
        }
    }

    gfx_driver_draw(frame, w * sizeof(uint16_t));

    sleep(5);
    free(frame);
    gfx_driver_shutdown();
    return 0;
}
