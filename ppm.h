#ifndef PPM_H
#define PPM_H

#include "vec3.h"

#define COLOR_BLACK \
    { .x = .0, .y = .0, .z = .0 }
#define COLOR_RED \
    { .x = 1.0, .y = .0, .z = .0 }
#define COLOR_GREEN \
    { .x = .5, .y = 1.0, .z = .7 }
#define COLOR_BLUE \
    { .x = .5, .y = .7, .z = 1.0 }
#define COLOR_WHITE \
    { .x = 1.0, .y = 1.0, .z = 1.0 }

void write_color(struct vec3* pixel_color);

#endif  // PPM_H
