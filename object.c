#include "object.h"

double hit_sphere(const ray_t* r, vec3_t center, double params[]) {
    double radius = params[0];
    double a, hb, c, d;
    struct vec3 work = r->orig;
    vec3_sub(&work, center);
    a = vec3_dot(r->dir, r->dir);
    hb = vec3_dot(work, r->dir);
    c = vec3_dot(work, work) - radius * radius;
    d = (hb * hb) - (a * c);
    if (d < 0) {
        return -1.0;
    } else {
        return (-hb - sqrt(d)) / a;
    }
}