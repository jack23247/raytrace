#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "vec3.h"

#define ASPECT_RATIO (4.0 / 3.0)

#define IMG_WIDTH 800
#define IMG_HEIGHT 600

#define VIEWPORT_WIDTH (2.0 * ASPECT_RATIO)
#define VIEWPORT_HEIGHT 2.0

#define FOCAL_LENGTH 1.0

extern struct vec3 origin;
extern struct vec3 horizontal;
extern struct vec3 vertical;
extern struct vec3 lower_left_corner;

void viewport_init(void);

#endif  // VIEWPORT_H
