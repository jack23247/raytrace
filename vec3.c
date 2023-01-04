#include "vec3.h"

#include <stdio.h>
#include <assert.h>

/**
 * @brief Initializes a vec3 structure.
 *
 * @param dest A pointer to the structure that's going to be initialized.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param z The z coordinate.
 */
void vec3_init(struct vec3* dest, double x, double y, double z) {
    assert(dest != NULL);
    dest->x = x;
    dest->y = y;
    dest->z = z;
}

/**
 * @brief Copies the contents of a vector into another.
 * \f$u\leftarrow u+w\f$
 *
 * @param dest A pointer to the target vec3.
 * @param u A copy of the data to be copied.
 */
void vec3_copy(struct vec3* dest, struct vec3 u) {
    assert(dest != NULL);
    dest->x = u.x;
    dest->y = u.y;
    dest->z = u.z;
}

/**
 * @brief Adds two vectors together, storing the sum into the first one.
 * \f$v\leftarrow v+w\f$
 *
 * @param u The first operand and destination of the operation.
 * @param v The second operand.
 */
void vec3_add(struct vec3* u, struct vec3 v) {
    assert(u != NULL);
    u->x += v.x;
    u->y += v.y;
    u->z += v.z;
}

/**
 * @brief Subtracts a vector from another, storing the difference into the first one.
 * \f$v\leftarrow v-w\f$
 *
 * @param u The first operand and destination of the operation.
 * @param v The second operand.
 */
void vec3_sub(struct vec3* u, struct vec3 v) {
    assert(u != NULL);
    u->x -= v.x;
    u->y -= v.y;
    u->z -= v.z;
}

/**
 * @brief Scales a vector by a constant (in place).
 * \f$u\leftarrow k*u\f$
 *
 * @param u The vector to be scaled.
 * @param t The scaling factor.
 */
void vec3_scale(struct vec3* u, double t) {
    assert(u != NULL);
    u->x *= t;
    u->y *= t;
    u->z *= t;
}

void vec3_mul(struct vec3* dest, struct vec3 u, struct vec3 v) {
    assert(dest != NULL);
    dest->x = u.x * v.x;
    dest->y = u.y * v.y;
    dest->z = u.z * v.z;
}

double vec3_dot(struct vec3 u, struct vec3 v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}


void vec3_cross(struct vec3* dest, struct vec3 u, struct vec3 v) {
    assert(dest != NULL);
    dest->x = (u.y * v.z) - (u.z * v.y);
    dest->y = (u.z * v.x) - (u.x * v.z);
    dest->z = (u.x * v.y) - (u.y * v.x);
}

double vec3_norm2(struct vec3 u) {
    return vec3_dot(u, u);
}

double vec3_norm(struct vec3 u) {
    return sqrt(vec3_norm2(u));
}

void vec3_unit(struct vec3* dest, struct vec3 u) {
    vec3_copy(dest, u);
    vec3_scale(dest, 1/vec3_norm(*dest));
}
