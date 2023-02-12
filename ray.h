#ifndef RAY_H
#define RAY_H

#include "ppm.h"
#include "vec3.h"
#include "viewport.h"
#include "object.h"

struct ray {
    struct vec3 orig;
    struct vec3 dir;
};

void ray_init(struct ray* ray, struct vec3 orig, struct vec3 dir);
void ray_copy(struct ray* dest, const struct ray* src);
struct vec3 ray_at(const struct ray* ray, double t);
struct vec3 ray_color(const struct ray* ray);
void ray_cast(struct ray* ray, int xpos, int ypos);

#endif
