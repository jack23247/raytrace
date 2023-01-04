#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include "color.h"

struct ray {
    struct vec3 orig;
    struct vec3 dir;
};

extern inline void ray_init(struct ray* ray, struct vec3 orig, struct vec3 dir) {
    // TODO assert()
    ray->orig = orig;
    ray->dir = dir;
}

extern inline void ray_copy(struct ray* dest, const struct ray* src) {
    dest->orig = src->orig;
    dest->dir = src->dir;
}

extern inline struct vec3 ray_at(const struct ray* ray, double t) {
    struct vec3 tmp;
    tmp = ray->dir;
    vec3_scale(&tmp, t);
    vec3_add(&tmp, ray->orig);
    return tmp;
}

extern inline struct vec3 ray_color(const struct ray* ray) {
    // Get a color based on the linear interpolation
    // of the vector's y coord (aka a vertical gradient)
    struct vec3 unit_direction;
    double t;
    struct vec3 c1, c2;
    vec3_unit(&unit_direction, ray->dir);
    t = 0.5 * (unit_direction.y + 1.0);
    vec3_init(&c1, 1.0, 1.0, 1.0); // White
    vec3_init(&c2, 0.5, 0.7, 1.0); // Blue-ish
    vec3_scale(&c1, 1.0-t);
    vec3_scale(&c2, t);
    vec3_add(&c1, c2);
    return c1;
}

#endif

