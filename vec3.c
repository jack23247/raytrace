#include "vec3.h"

#include <stdio.h>
#include <stdlib.h>
#include "liberror/src/liberror.h"

/**
 * @brief Copies the contents of a vec3 into another.
 *
 * @param dest A pointer to the target vec3.
 * @param src A pointer to the source vec3.
 */
void vec3_copy(struct vec3* dest, const struct vec3* src) {
    LIBERROR_IS_NULL(dest, "dest");
    LIBERROR_IS_NULL(src, "src");
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
}


/**
 * @brief Initializes a vec3 structure.
 *
 * @param dest A pointer to the vec3 that's going to be initialized.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param z The z coordinate.
 */
void vec3_init(struct vec3* dest, double x, double y, double z) {
    LIBERROR_IS_NULL(dest, "dest");
    dest->x = x;
    dest->y = y;
    dest->z = z;
}

/**
 * @brief Adds two vec3s together, storing the sum into the first one v<-v+w
 *
 * @param v The
 * @param w p_w:...
 */
void vec3_add(struct vec3* v, const struct vec3* w) {
    LIBERROR_IS_NULL(v, "v");
    LIBERROR_IS_NULL(w, "w");
    v->x += w->x;
    v->y += w->y;
    v->z += w->z;
}

void vec3_sub(struct vec3* v, const struct vec3* w) {
    LIBERROR_IS_NULL(v, "v");
    LIBERROR_IS_NULL(w, "w");
    v->x -= w->x;
    v->y -= w->y;
    v->z -= w->z;
}

void vec3_scale(struct vec3* v, double t) {
    LIBERROR_IS_NULL(v, "v");
    v->x *= t;
    v->y *= t;
    v->z *= t;
}

void vec3_mul(struct vec3* dest, const struct vec3* u, const struct vec3* v) {
    LIBERROR_IS_NULL(dest, "dest");
    LIBERROR_IS_NULL(u, "u");
    LIBERROR_IS_NULL(v, "v");
    dest->x = u->x * v->x;
    dest->y = u->y * v->y;
    dest->z = u->z * v->z;
}

double vec3_dot(const struct vec3* u, const struct vec3* v) {
    LIBERROR_IS_NULL(u, "u");
    LIBERROR_IS_NULL(v, "v");
    return u->x * v->x + u->y * v->y + u->z * v->z;
}

void vec3_cross(struct vec3* dest, const struct vec3* u, const struct vec3* v) {
    LIBERROR_IS_NULL(dest, "dest");
    LIBERROR_IS_NULL(u, "u");
    LIBERROR_IS_NULL(v, "v");
    dest->x = u->y * v->z - u->z * v->y;
    dest->y = u->z * v->x - u->x * v->z;
    // dest->z = u->x * v->y - u->y * v->x;
}

double vec3_norm2(const struct vec3* v) {
    LIBERROR_IS_NULL(v, "v");
    return vec3_dot(v, v);
}

double vec3_norm(const struct vec3* v) {
    return sqrt(vec3_norm2(v));
}

void vec3_unit(struct vec3* dest, const struct vec3* src) {
    vec3_copy(dest, src);
    vec3_scale(dest, 1/vec3_norm(dest));
}
