
// sf3000_memdebug.c - Framebuffer debugger for HcLinux with screen and file logging
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <stdint.h>

#define FB_PATH "/dev/fb0"
#define LOG_FILE "/mnt/sdcard/memdebug.log"
#define LOG_HEIGHT 16  // height in lines of debug output

static volatile uint16_t *fb = 0;
static int log_fd = -1;

void log_line(const char *text) {
    if (log_fd >= 0 && text) {
        write(log_fd, text, strlen(text));
        write(log_fd, "\n", 1);
    }
}

void draw_text_line(int y, const char *text) {
    int x = 0;
    while (text && *text && x < 80 && y < LOG_HEIGHT) {
        uint16_t color = 0xFFFF;
        int bx = x * 8;
        int by = y * 8;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                fb[(by + j) * 640 + (bx + i)] = (*text & 0x40) ? color : 0x0000;
            }
        }
        text++;
        x++;
    }
}

void utoa_hex(unsigned int val, char *buf, int digits) {
    for (int i = digits - 1; i >= 0; i--) {
        buf[i] = "0123456789ABCDEF"[val & 0xF];
        val >>= 4;
    }
    buf[digits] = 0;
}

void memdebug_main() {
    int fd = open(FB_PATH, O_RDWR);
    if (fd < 0)
        return;

    log_fd = open(LOG_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

    ioctl(fd, FBIOGET_FSCREENINFO, &finfo);
    ioctl(fd, FBIOGET_VSCREENINFO, &vinfo);

    int screensize = vinfo.yres_virtual * finfo.line_length;

    fb = (uint16_t *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (fb == (void *)-1)
        return;

    for (int i = 0; i < (640 * 480); i++)
        fb[i] = 0;

    char line[64];
    char val[16];
    int line_num = 0;

    draw_text_line(line_num++, "SF3000 MEMDEBUG");
    log_line("SF3000 MEMDEBUG");

    utoa_hex((unsigned int)(uintptr_t)fb, val, 8);
    snprintf(line, sizeof(line), "FB mmap addr: 0x%s", val);
    draw_text_line(line_num++, line);
    log_line(line);

    utoa_hex((unsigned int)finfo.smem_start, val, 8);
    snprintf(line, sizeof(line), "FB phys addr: 0x%s", val);
    draw_text_line(line_num++, line);
    log_line(line);

    snprintf(line, sizeof(line), "Resolution: %dx%d", vinfo.xres, vinfo.yres);
    draw_text_line(line_num++, line);
    log_line(line);

    snprintf(line, sizeof(line), "Line length: %d", finfo.line_length);
    draw_text_line(line_num++, line);
    log_line(line);

    snprintf(line, sizeof(line), "Bits per pixel: %d", vinfo.bits_per_pixel);
    draw_text_line(line_num++, line);
    log_line(line);

    munmap((void *)fb, screensize);
    close(fd);
    if (log_fd >= 0)
        close(log_fd);
}

void _start() {
    memdebug_main();
    for (;;);
}
