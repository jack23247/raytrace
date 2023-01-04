#ifndef VEC3_H
#define VEC3_H

#include <math.h> // should be replaced by my own functions

struct vec3 {
    double x, y, z;
};

void vec3_copy(struct vec3* dest, const struct vec3* src);
void vec3_init(struct vec3* dest, double x, double y, double z);
void vec3_add(struct vec3* v, const struct vec3* w);
void vec3_sub(struct vec3* v, const struct vec3* w);
void vec3_scale(struct vec3* v, double t);
void vec3_mul(struct vec3* dest, const struct vec3* u, const struct vec3* v);
double vec3_dot(const struct vec3* u, const struct vec3* v);
void vec3_cross(struct vec3* dest, const struct vec3* u, const struct vec3* v);
double vec3_norm2(const struct vec3* v);
double vec3_norm(const struct vec3* v);
void vec3_unit(struct vec3* dest, const struct vec3* src);

#endif
