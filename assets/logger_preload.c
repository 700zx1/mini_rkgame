
#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

static FILE *log_file = NULL;
static int filter_enabled = 0;

static void init_log() {
    if (!log_file) {
        log_file = fopen("/mnt/sdcard/runtime.log", "a");
        if (log_file) setvbuf(log_file, NULL, _IONBF, 0);
        const char *filter_env = getenv("LOG_FILTER");
        filter_enabled = (filter_env && strcmp(filter_env, "1") == 0);
    }
}

static long long timestamp_us() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)(ts.tv_sec * 1000000LL + ts.tv_nsec / 1000);
}

void *dlopen(const char *filename, int flags) {
    init_log();
    void *(*real_dlopen)(const char*, int) = dlsym(RTLD_NEXT, "dlopen");
    if (log_file) fprintf(log_file, "[%lld us] [dlopen] %s\n", timestamp_us(), filename);
    return real_dlopen(filename, flags);
}

void *dlsym(void *handle, const char *symbol) {
    init_log();
    void *(*real_dlsym)(void*, const char*) = dlsym(RTLD_NEXT, "dlsym");

    int match = 0;
    if (filter_enabled) {
        const char *filter[] = {
            "retro_run", "retro_load_game", "retro_init", "fbdev_draw_frame",
            "fbdev_init", "video_driver_get_size", "retro_set_video_refresh",
            "retro_set_input_poll", "retro_set_input_state", NULL
        };
        for (int i = 0; filter[i]; ++i) {
            if (strcmp(symbol, filter[i]) == 0) {
                match = 1;
                break;
            }
        }
    } else {
        match = 1;
    }

    if (match && log_file)
        fprintf(log_file, "[%lld us] [dlsym] %s\n", timestamp_us(), symbol);

    return real_dlsym(handle, symbol);
}

int open(const char *pathname, int flags, ...) {
    init_log();
    mode_t mode = 0;
    if (__OPEN_NEEDS_MODE(flags)) {
        va_list ap;
        va_start(ap, flags);
        mode = va_arg(ap, mode_t);
        va_end(ap);
    }
    int (*real_open)(const char*, int, ...) = dlsym(RTLD_NEXT, "open");
    if (log_file) fprintf(log_file, "[%lld us] [open] %s\n", timestamp_us(), pathname);
    return real_open(pathname, flags, mode);
}

ssize_t read(int fd, void *buf, size_t count) {
    init_log();
    ssize_t (*real_read)(int, void*, size_t) = dlsym(RTLD_NEXT, "read");
    ssize_t ret = real_read(fd, buf, count);
    if (log_file) fprintf(log_file, "[%lld us] [read] fd=%d, bytes=%zd\n", timestamp_us(), fd, ret);
    return ret;
}

ssize_t write(int fd, const void *buf, size_t count) {
    init_log();
    ssize_t (*real_write)(int, const void*, size_t) = dlsym(RTLD_NEXT, "write");
    ssize_t ret = real_write(fd, buf, count);
    if (log_file) fprintf(log_file, "[%lld us] [write] fd=%d, bytes=%zd\n", timestamp_us(), fd, ret);
    return ret;
}

int ioctl(int fd, unsigned long request, ...) {
    init_log();
    va_list ap;
    va_start(ap, request);
    void *argp = va_arg(ap, void *);
    va_end(ap);

    int (*real_ioctl)(int, unsigned long, void *) = dlsym(RTLD_NEXT, "ioctl");
    if (log_file) fprintf(log_file, "[%lld us] [ioctl] fd=%d, req=0x%lx\n", timestamp_us(), fd, request);
    return real_ioctl(fd, request, argp);
}

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    init_log();
    void *(*real_mmap)(void*, size_t, int, int, int, off_t) = dlsym(RTLD_NEXT, "mmap");
    void *res = real_mmap(addr, length, prot, flags, fd, offset);
    if (log_file) fprintf(log_file, "[%lld us] [mmap] fd=%d, len=%zu, res=%p\n", timestamp_us(), fd, length, res);
    return res;
}
