
#ifndef GFX_DRIVER_LAYER_H
#define GFX_DRIVER_LAYER_H

#ifdef __cplusplus
extern "C" {
#endif

int gfx_driver_load(const char *path);
void gfx_driver_init();
void gfx_driver_shutdown();
void gfx_driver_draw(const void *frame, int pitch);
void gfx_driver_get_size(int *w, int *h);

#ifdef __cplusplus
}
#endif

#endif // GFX_DRIVER_LAYER_H
