#ifndef SCENE_H
#define SCENE_H

#include <stddef.h>

#include "object.h"
#include "ppm.h"

#define SKY_BOTTOM COLOR_WHITE
#define SKY_TOP COLOR_BLUE

struct object ground = {
    .center = { .x = .0, .y = -100.5, .z = -1.0 },
    .color = COLOR_GREEN,
    .hit = &hit_sphere,
    .params[0] = 100.0,
    .flags = STANDARD,
    .next = NULL
};

struct object my_sphere = {
    .center = { .x = .0, .y = .0, .z = -1.0 },
    .color = COLOR_WHITE,
    .hit = &hit_sphere,
    .params[0] = 0.5,
    .flags = NORMALS,
    .next = &ground
};

struct object* scene = &my_sphere;

#endif  // SCENE_H
