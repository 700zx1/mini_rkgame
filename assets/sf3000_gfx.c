
// sf3000_gfx.c - Minimal HiChip-based graphics driver for SF3000/GB350
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define FB_WIDTH   640      // Set to correct SF3000 screen width
#define FB_HEIGHT  480      // Set to correct SF3000 screen height
#define FB_BPP     2        // 2 bytes per pixel (RGB565)
#define FB_SIZE    (FB_WIDTH * FB_HEIGHT * FB_BPP)

static volatile uint16_t *fb = NULL;

int sf3000_gfx_init(void) {
    int fd = open("/dev/fb0", O_RDWR);
    if (fd < 0) {
        perror("open(/dev/fb0)");
        return -1;
    }

    fb = (uint16_t *)mmap(NULL, FB_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    if (fb == MAP_FAILED) {
        perror("mmap framebuffer");
        return -1;
    }

    // Clear framebuffer to black
    memset((void *)fb, 0, FB_SIZE);
    return 0;
}

void sf3000_gfx_shutdown(void) {
    if (fb && fb != MAP_FAILED) {
        munmap((void *)fb, FB_SIZE);
        fb = NULL;
    }
}

void sf3000_gfx_draw_frame(const void *src, int pitch) {
    if (!fb) return;

    const uint8_t *src_row = (const uint8_t *)src;
    for (int y = 0; y < FB_HEIGHT; y++) {
        memcpy((void *)(fb + y * FB_WIDTH), src_row + y * pitch, FB_WIDTH * FB_BPP);
    }
}

void sf3000_gfx_fill_color(uint16_t color) {
    if (!fb) return;

    for (int i = 0; i < (FB_WIDTH * FB_HEIGHT); i++) {
        fb[i] = color;
    }
}
