#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "vec3.h"

extern inline void write_color(struct vec3* pixel_color) {
    int r = trunc(255.999 * pixel_color->x);
    int g = trunc(255.999 * pixel_color->y);
    int b = trunc(255.999 * pixel_color->z);
    printf("%d %d %d\n", r, g, b);
}

#endif
