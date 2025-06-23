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

void probe_audio_devices() {
    log_line("=== Audio Devices ===");
    const char *audio_paths[] = { "/dev/dsp", "/dev/audio", "/dev/snd/pcmC0D0p" };
    for (int i = 0; i < 3; i++) {
        if (access(audio_paths[i], F_OK) == 0) {
            log_line(audio_paths[i]);
        }
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


void show_visual_status() {
    int fd = open("/dev/fb0", O_RDWR);
    if (fd < 0) return;

    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    ioctl(fd, FBIOGET_FSCREENINFO, &finfo);
    ioctl(fd, FBIOGET_VSCREENINFO, &vinfo);

    int screensize = vinfo.yres_virtual * finfo.line_length;
    uint16_t *fb = (uint16_t *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (fb == (void *)-1) {
        close(fd);
        return;
    }

    // Fill top 1/4 of screen green (success status)
    int pixels = (vinfo.xres * vinfo.yres) / 4;
    for (int i = 0; i < pixels; i++)
        fb[i] = 0x07E0; // Green RGB565

    munmap((void *)fb, screensize);
    close(fd);
}

void _start() {
    log_fd = open(LOG_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (log_fd < 0)
        return;

    log_line("SF3000 SYSTEM PROBE BEGIN");
    probe_framebuffer();
    probe_input_devices();
    probe_audio_devices();
    probe_storage_mounts();
    probe_proc_basic();
    log_line("SF3000 SYSTEM PROBE END");
    show_visual_status();

    close(log_fd);
    for (;;);
}

int main(int argc, char **argv) {
    _start();
    return 0;
}
