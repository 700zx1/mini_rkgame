
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "sf3000_gfx.h"

#define WIDTH  640
#define HEIGHT 480

int main(void) {
    printf("[INFO] Initializing graphics...\n");
    if (sf3000_gfx_init() != 0) {
        fprintf(stderr, "[ERROR] Failed to initialize graphics\n");
        return 1;
    }

    printf("[INFO] Allocating frame buffer...\n");
    uint16_t *image = (uint16_t *)malloc(WIDTH * HEIGHT * sizeof(uint16_t));
    if (!image) {
        fprintf(stderr, "[ERROR] Failed to allocate image buffer\n");
        sf3000_gfx_shutdown();
        return 1;
    }

    printf("[INFO] Creating color bars...\n");
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

    printf("[INFO] Rendering frame to screen...\n");
    sf3000_gfx_draw_frame(image, WIDTH * sizeof(uint16_t));

    printf("[INFO] Displayed image. Sleeping 5 seconds...\n");
    sleep(5);

    printf("[INFO] Cleaning up...\n");
    free(image);
    sf3000_gfx_shutdown();
    printf("[INFO] Shutdown complete.\n");

    return 0;
}
