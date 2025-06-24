// sf3000_probe.c - Comprehensive system probe for SF3000/GB350 runtime detection
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <linux/input.h>
#include <sys/mman.h>
#include <unistd.h>
#include <dlfcn.h>
#include <linux/input.h>
#include <time.h>

#define LOG_FILE "/mnt/sdcard/probe.log"

int log_fd = -1;

void log_line(const char *text) {
    if (log_fd >= 0 && text) {
        write(log_fd, text, strlen(text));
        write(log_fd, "\n", 1);
    }
}

void log_hex(const char *prefix, unsigned int val) {
    char line[64];
    snprintf(line, sizeof(line), "%s0x%08X", prefix, val);
    log_line(line);
}

void probe_framebuffer() {
    log_line("=== Framebuffer Info ===");
    int fd = open("/dev/fb0", O_RDWR);
    if (fd < 0) {
        log_line("Framebuffer open failed.");
        return;
    }

    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    ioctl(fd, FBIOGET_FSCREENINFO, &finfo);
    ioctl(fd, FBIOGET_VSCREENINFO, &vinfo);

    char line[128];
    snprintf(line, sizeof(line), "Resolution: %dx%d", vinfo.xres, vinfo.yres);
    log_line(line);

    snprintf(line, sizeof(line), "Line length: %d", finfo.line_length);
    log_line(line);

    snprintf(line, sizeof(line), "Bits per pixel: %d", vinfo.bits_per_pixel);
    log_line(line);

    log_hex("Physical address: ", finfo.smem_start);

    close(fd);
}

void probe_input_devices() {
    log_line("=== Input Devices ===");
    DIR *dir = opendir("/dev/input");
    if (!dir) {
        log_line("No /dev/input directory.");
        return;
    }

    struct dirent *entry;
    char path[64];
    while ((entry = readdir(dir)) != NULL) {
        if (strncmp(entry->d_name, "event", 5) == 0) {
            snprintf(path, sizeof(path), "/dev/input/%s", entry->d_name);
            int fd = open(path, O_RDONLY);
            if (fd >= 0) {
                char name[64] = "Unknown";
                ioctl(fd, EVIOCGNAME(sizeof(name)), name);
                write(log_fd, "Device: ", 8);
                write(log_fd, path, strlen(path));
                write(log_fd, " (", 2);
                write(log_fd, name, strlen(name));
                write(log_fd, ")\n", 2);
                close(fd);
            }
        }
    }
    closedir(dir);
}

void probe_input_events() {
    log_line("=== Input Event Test (3s) ===");
    DIR *dir = opendir("/dev/input");
    if (!dir) {
        log_line("No /dev/input directory.");
        return;
    }
    struct dirent *entry;
    char path[64];
    while ((entry = readdir(dir)) != NULL) {
        if (strncmp(entry->d_name, "event", 5) == 0) {
            snprintf(path, sizeof(path), "/dev/input/%s", entry->d_name);
            int fd = open(path, O_RDONLY | O_NONBLOCK);
            if (fd >= 0) {
                struct input_event ev;
                time_t start = time(NULL);
                while (time(NULL) - start < 3) {
                    ssize_t n = read(fd, &ev, sizeof(ev));
                    if (n == sizeof(ev)) {
                        char line[128];
                        snprintf(line, sizeof(line), "event: type=%d code=%d value=%d", ev.type, ev.code, ev.value);
                        log_line(line);
                    }
                }
                close(fd);
            }
        }
    }
    closedir(dir);
}

void probe_audio_devices() {
    log_line("=== Audio Devices ===");
    const char *audio_paths[] = { "/dev/dsp", "/dev/audio", "/dev/snd/pcmC0D0p" };
    for (int i = 0; i < 3; i++) {
        if (access(audio_paths[i], F_OK) == 0) {
            log_line(audio_paths[i]);
        }
    }
}

void probe_audio_output() {
    log_line("=== Audio Output Test ===");
    int fd = open("/dev/dsp", O_WRONLY);
    if (fd >= 0) {
        char silence[4096] = {0};
        write(fd, silence, sizeof(silence));
        log_line("Wrote 4096 bytes of silence to /dev/dsp");
        close(fd);
    } else {
        log_line("Could not open /dev/dsp for writing.");
    }
}

void probe_storage_mounts() {
    log_line("=== Storage Mounts ===");
    const char *paths[] = { "/mnt/sdcard", "/media/mmc", "/mnt/usb", "/mnt/" };
    struct stat st;
    for (int i = 0; i < 4; i++) {
        if (stat(paths[i], &st) == 0 && S_ISDIR(st.st_mode)) {
            log_line(paths[i]);
        }
    }
}

void probe_filesystem_write() {
    log_line("=== Filesystem Write Test ===");
    const char *testfile = "/mnt/sdcard/probe_write_test.tmp";
    int fd = open(testfile, O_CREAT | O_WRONLY, 0644);
    if (fd >= 0) {
        write(fd, "test", 4);
        close(fd);
        log_line("Write to /mnt/sdcard successful.");
        unlink(testfile);
    } else {
        log_line("Write to /mnt/sdcard failed.");
    }
}

void probe_proc_basic() {
    log_line("=== /proc Info ===");
    char buf[256];
    int fd;

    fd = open("/proc/cpuinfo", O_RDONLY);
    if (fd >= 0) {
        int len = read(fd, buf, sizeof(buf) - 1);
        if (len > 0) {
            buf[len] = 0;
            log_line("--- CPU Info ---");
            write(log_fd, buf, len);
        }
        close(fd);
    }

    fd = open("/proc/meminfo", O_RDONLY);
    if (fd >= 0) {
        int len = read(fd, buf, sizeof(buf) - 1);
        if (len > 0) {
            buf[len] = 0;
            log_line("--- Mem Info ---");
            write(log_fd, buf, len);
        }
        close(fd);
    }
}

void probe_dynamic_loading() {
    log_line("=== Dynamic Loading Test ===");
    void *handle = dlopen("/mnt/sdcard/cubegm/cores/vice_x64_libretro.so", RTLD_LAZY);
    if (handle) {
        void *sym = dlsym(handle, "retro_init");
        if (sym) {
            log_line("Found symbol retro_init in core.");
        } else {
            log_line("Could not find symbol retro_init.");
        }
        dlclose(handle);
    } else {
        log_line("Could not dlopen core.");
    }
}

void log_fbinfo(const char *fbdev, struct fb_var_screeninfo *vinfo, struct fb_fix_screeninfo *finfo) {
    char line[256];
    snprintf(line, sizeof(line), "[FBINFO] %s: xres=%d yres=%d xres_virtual=%d yres_virtual=%d bpp=%d line_length=%d red(offset=%d len=%d) green(offset=%d len=%d) blue(offset=%d len=%d) transp(offset=%d len=%d) smem_start=0x%lX smem_len=%d", 
        fbdev, vinfo->xres, vinfo->yres, vinfo->xres_virtual, vinfo->yres_virtual, vinfo->bits_per_pixel, finfo->line_length, 
        vinfo->red.offset, vinfo->red.length, vinfo->green.offset, vinfo->green.length, vinfo->blue.offset, vinfo->blue.length, vinfo->transp.offset, vinfo->transp.length, (unsigned long)finfo->smem_start, finfo->smem_len);
    log_line(line);
}

void try_visual_on_fb(const char *fbdev) {
    int fd = open(fbdev, O_RDWR);
    if (fd < 0) {
        char msg[128];
        snprintf(msg, sizeof(msg), "[VISUAL] Could not open %s", fbdev);
        log_line(msg);
        return;
    }
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    ioctl(fd, FBIOGET_FSCREENINFO, &finfo);
    ioctl(fd, FBIOGET_VSCREENINFO, &vinfo);
    log_fbinfo(fbdev, &vinfo, &finfo);
    int screensize = vinfo.yres_virtual * finfo.line_length;
    void *fb = mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (fb == MAP_FAILED) {
        char msg[128];
        snprintf(msg, sizeof(msg), "[VISUAL] mmap failed for %s", fbdev);
        log_line(msg);
        close(fd);
        return;
    }
    int visible_pixels = vinfo.xres * vinfo.yres;
    int green_pixels = visible_pixels; // draw full screen for visibility
    if (vinfo.bits_per_pixel == 16) {
        uint16_t *fb16 = (uint16_t *)fb;
        for (int i = 0; i < green_pixels; i++)
            fb16[i] = 0x07E0; // Green RGB565
        log_line("[VISUAL] 16bpp: wrote 0x07E0 (RGB565 green)");
    } else if (vinfo.bits_per_pixel == 32) {
        uint32_t *fb32 = (uint32_t *)fb;
        // Draw a unique pattern: diagonal lines
        for (int y = 0; y < vinfo.yres; y++) {
            for (int x = 0; x < vinfo.xres; x++) {
                int idx = y * vinfo.xres + x;
                if (x == y || x == vinfo.xres - y - 1) {
                    fb32[idx] = 0xFFFF0000; // Red diagonal
                } else if (x % 50 == 0 || y % 50 == 0) {
                    fb32[idx] = 0xFF0000FF; // Blue grid
                } else {
                    fb32[idx] = 0xFF00FF00; // Green background
                }
            }
        }
        log_line("[VISUAL] 32bpp: drew green with red diagonals and blue grid");
        msync(fb, screensize, MS_SYNC);
        // Try panning for fb0
        if (strcmp(fbdev, "/dev/fb0") == 0) {
            vinfo.yoffset = 0;
            if (ioctl(fd, FBIOPAN_DISPLAY, &vinfo) == -1) {
                log_line("[VISUAL] FBIOPAN_DISPLAY failed on fb0");
            } else {
                log_line("[VISUAL] FBIOPAN_DISPLAY succeeded on fb0");
            }
        }
        usleep(5000000); // 5 seconds
    } else {
        log_line("[VISUAL] Unsupported bpp, no color written");
    }
    munmap(fb, screensize);
    close(fd);
}

void show_visual_status() {
    try_visual_on_fb("/dev/fb0");
    try_visual_on_fb("/dev/fb1");
}

void _start() {
    log_fd = open(LOG_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (log_fd < 0)
        return;

    log_line("SF3000 SYSTEM PROBE BEGIN");
    probe_framebuffer();
    probe_input_devices();
    probe_input_events();      // NEW
    probe_audio_devices();
    probe_audio_output();      // NEW
    probe_storage_mounts();
    probe_filesystem_write();  // NEW
    probe_proc_basic();
    probe_dynamic_loading();   // NEW
    log_line("SF3000 SYSTEM PROBE END");
    show_visual_status();

    close(log_fd);
    for (;;);
}

int main(int argc, char **argv) {
    _start();
    return 0;
}
