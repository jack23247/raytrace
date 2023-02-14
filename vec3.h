/**
 * @file vec3.h
 * @author Jacopo Maltagliati
 * @date 14 Feb 2023
 * @brief Library for handling three-dimensional vectors.
 * @copyright Copyright (c) 2022-23, Jacopo Maltagliati.
 * Released under the BSD 3-Clause License.
 */

#ifndef VEC3_H
#define VEC3_H

/**
 * @brief Initializer list for the point \f$[0,0,0]\f$ in 3-D space
 */
#define VEC3_ZERO \
    { .x = .0, .y = .0, .z = .0 }

/**
 * @brief Multipurpose three-dimensional vector structure. May be used for
 * points in 3-D space, vectors and the likes.
 */
struct vec3 {
    double x, y, z;
};

/**
 * @brief Initializes a vec3 structure.
 *
 * @param dest A pointer to the structure that's going to be initialized.
 * @param x The \f$x\f$ coordinate.
 * @param y The \f$y\f$ coordinate.
 * @param z The \f$z\f$ coordinate.
 */
void vec3_init(struct vec3* dest, double x, double y, double z);

/**
 * @brief Copies the contents of a vector into another.
 *
 * \f$u\leftarrow u+w\f$.
 *
 * @param dest A pointer to the target of the copy.
 * @param u A copy of the data to be copied.
 */
void vec3_copy(struct vec3* dest, struct vec3 u);

/**
 * @brief Adds two vectors together, storing the sum into the first one.
 *
 * \f$v\leftarrow v+w\f$.
 *
 * @param u A pointer to the first operand and destination of the operation.
 * @param v The second operand.
 */
void vec3_add(struct vec3* u, struct vec3 v);

/**
 * @brief Subtracts a vector from another, storing the difference into the first
 * one.
 *
 * \f$v\leftarrow v-w\f$
 *
 * @param u A pointer to the first operand and destination of the operation.
 * @param v The second operand.
 */
void vec3_sub(struct vec3* u, struct vec3 v);

/**
 * @brief Scales a vector by a constant.
 *
 * \f$u\leftarrow t*u\f$
 *
 * @param u A pointer to the vector to be scaled.
 * @param t The scaling factor.
 */
void vec3_scale(struct vec3* u, double t);

/**
 * @brief Adds a scalar to each component of the vector.
 *
 * \f$
 *  u_x\leftarrow u_x+t\\
 *  u_y\leftarrow u_y+t\\
 *  u_z\leftarrow u_z+t
 * \f$
 *
 * @param u A pointer to the vector to be added to.
 * @param t The scalar quantity to be added.
 */
void vec3_add_scalar(struct vec3* u, double t);

/**
 * @brief Multiplies the components of a vector by the components of another.
 *
 * \f$w_x\leftarrow u_x\times v_x$\f
 *
 * @param dest A pointer to the destination of the operation.
 * @param u The first operand.
 * @param v The second operand.
 */
void vec3_mul(struct vec3* dest, struct vec3 u, struct vec3 v);

/**
 * @brief Computes the dot product of two vectors.
 *
 * @param u The first operand.
 * @param v The second operand.
 * @return The dot product of \f$u\f$ and \f$v\f$.
 */
double vec3_dot(struct vec3 u, struct vec3 v);

/**
 * @brief Computes the cross product of two vectors.
 *
 * @param dest A pointer to the destination of the operation.
 * @param u The first operand.
 * @param v The second operand.
 */
void vec3_cross(struct vec3* dest, struct vec3 u, struct vec3 v);

/**
 * @brief Computes the squared norm of a vector, i.e. its length, squared.
 *
 * @param u The vector.
 * @return The squared norm of the vector.
 */
double vec3_norm2(struct vec3 u);

/**
 * @brief Computes the norm of a vector, i.e. its length.
 *
 * @param u The vector.
 * @return The norm of the vector.
 */
double vec3_norm(struct vec3 u);


/**
 * @brief Computes the unit vector associated with a vector \f$u\f$.
 *
 * @param dest A pointer to the destination of the operation.
 * @param u The vector.
 */
void vec3_unit(struct vec3* dest, struct vec3 u);

#endif
