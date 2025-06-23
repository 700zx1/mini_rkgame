
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sf3000_gfx.h"

#define WIDTH  640
#define HEIGHT 480

int main(void) {
    if (sf3000_gfx_init() != 0) {
        fprintf(stderr, "Failed to initialize graphics\n");
        return 1;
    }

    // Allocate a test image buffer (RGB565)
    uint16_t *image = (uint16_t *)malloc(WIDTH * HEIGHT * sizeof(uint16_t));
    if (!image) {
        fprintf(stderr, "Failed to allocate image buffer\n");
        sf3000_gfx_shutdown();
        return 1;
    }

    // Create horizontal color bars: Red, Green, Blue, Yellow, Cyan, Magenta, White, Black
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
    int bar_height = HEIGHT / 8;
    for (int y = 0; y < HEIGHT; y++) {
        int bar = y / bar_height;
        uint16_t color = colors[bar % 8];
        for (int x = 0; x < WIDTH; x++) {
            image[y * WIDTH + x] = color;
        }
    }

    // Render to screen
    sf3000_gfx_draw_frame(image, WIDTH * sizeof(uint16_t));

    // Wait a few seconds before exiting
    sleep(5);

    free(image);
    sf3000_gfx_shutdown();
    return 0;
}
