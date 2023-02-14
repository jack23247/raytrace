/**
 * @file object.h
 * @author Jacopo Maltagliati
 * @date 14 Feb 2023
 * @brief Utilities for building a scene composed of a list of objects.
 * @copyright Copyright (c) 2022-23, Jacopo Maltagliati.
 * Released under the BSD 3-Clause License.
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>

#include "ray.h"
#include "vec3.h"

typedef struct ray ray_t;
typedef struct vec3 vec3_t;

#define STANDARD 0x01 /**< Standard flat coloring method. */
#define NORMALS 0x02  /**< Use surface normals to color the object. */

/**
 * @brief Defines an object that can be placed in the world and a ray can
 * intersect.
 */
struct object {
    struct object* next; /**< Points to the next object in the scene. */
    double (*hit)(
        const ray_t* r, vec3_t center,
        const double params[]); /**< Points to a generic hit function. The
                                   parameter vector has different uses
                                   depending on the hit function. */
    double params[4]; /**< Holds parameters for the hit function, has different
                         uses depending on the type of object. */
    struct vec3 center; /**< The center of the object. */
    struct vec3 color;  /**< The color of the object. */
    uint8_t flags;      /**< Holds object flags, currently used for defining
                           materials. */
};

extern struct object* scene; /**< Pointer to the first object in the scene */

// TODO allow for serializing and deserializing scenes

/**
 * @brief Hit function for a spherical object.
 *
 * @param r The ray we're trying to intersect.
 * @param center The center of the sphere.
 * @param params Parameter list - 0: Sphere radius
 * @return The blabla of the blas
 */
double hit_sphere(const ray_t* r, vec3_t center, const double params[]);

#endif  // OBJECT_H
