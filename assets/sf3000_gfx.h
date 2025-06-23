
#ifndef SF3000_GFX_H
#define SF3000_GFX_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int sf3000_gfx_init(void);
void sf3000_gfx_shutdown(void);
void sf3000_gfx_draw_frame(const void *src, int pitch);
void sf3000_gfx_fill_color(uint16_t color);

#ifdef __cplusplus
}
#endif

#endif // SF3000_GFX_H
