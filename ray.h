/**
 * @file ray.h
 * @author Jacopo Maltagliati
 * @date 14 Feb 2023
 * @brief Implements the functionality for the Ray.
 * @copyright Copyright (c) 2022-23, Jacopo Maltagliati.
 * Released under the BSD 3-Clause License.
 */

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/**
 * @brief Structure representing a Ray, which is essentially an applied vector
 * in 3-D space defined by two points: an origin and a direction.
 */
struct ray {
    struct vec3 orig; /**< The origin of the Ray. */
    struct vec3 dir; /**< The direction of the Ray. */
};

void ray_init(struct ray* ray, struct vec3 orig, struct vec3 dir);
void ray_copy(struct ray* dest, const struct ray* src);

struct vec3 ray_at(const struct ray* ray, double t);
void ray_cast(struct ray* ray, int xpos, int ypos);

/**
 * @brief Derive a color based on what the ray hits. The function iterates on
 * the global scene and tries to determine whether an object is intersected.
 * The first encountered object gets the precedence over the others (simulates
 * Z-buffering if the objects are sorted according to their distance from the
 * camera). If an object is intersected, the function will return the color of
 * said object, according to its flags. If the ray does not intersect anything,
 * the color of the sky will be returned. The sky is a linear interpolation
 * (i.e. a gradient) between two colors (\f$c_1\f$ and \f$c_2\f$).
 *
 * @param ray
 * @return The color of the scene at the point where the ray intersects it.
 */
struct vec3 ray_color(const struct ray* ray);

#endif
