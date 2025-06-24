#include <stdio.h>
__attribute__((constructor))
void init() {
    FILE *f = fopen("/mnt/sdcard/preload_test.log", "a");
    if (f) {
        fprintf(f, "Preload library loaded!\n");
        fclose(f);
    }
}