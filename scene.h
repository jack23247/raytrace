/**
 * @file scene.h
 * @author Jacopo Maltagliati
 * @date 14 Feb 2023
 * @brief Describes a fixed scene.
 * @copyright Copyright (c) 2022-23, Jacopo Maltagliati.
 * Released under the BSD 3-Clause License.
 */

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
