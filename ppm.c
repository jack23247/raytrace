#include "ppm.h"

#include <assert.h>
#include <stdio.h>

#include "openlibm/include/openlibm.h"

extern inline void write_color(struct vec3* pixel_color) {
    assert(pixel_color != NULL);
    int r = (int)trunc(255.999 * pixel_color->x);
    int g = (int)trunc(255.999 * pixel_color->y);
    int b = (int)trunc(255.999 * pixel_color->z);
    printf("%d %d %d\n", r, g, b);
}
