#ifndef VEC3_H
#define VEC3_H

#define VEC3_ZERO \
    { .x = .0, .y = .0, .z = .0 }

struct vec3 {
    double x, y, z;
};

void vec3_init(struct vec3* dest, double x, double y, double z);
void vec3_copy(struct vec3* dest, struct vec3 u);

void vec3_add(struct vec3* u, struct vec3 v);
void vec3_sub(struct vec3* u, struct vec3 v);
void vec3_scale(struct vec3* u, double t);
void vec3_add_scalar(struct vec3* u, double t);

void vec3_mul(struct vec3* dest, struct vec3 u, struct vec3 v);
double vec3_dot(struct vec3 u, struct vec3 v);
void vec3_cross(struct vec3* dest, struct vec3 u, struct vec3 v);

double vec3_norm2(struct vec3 u);
double vec3_norm(struct vec3 u);
void vec3_unit(struct vec3* dest, struct vec3 u);

#endif
