/**
 * @file viewport.h
 * @author Jacopo Maltagliati
 * @date 14 Feb 2023
 * @brief Defines the viewport of the scene and allows to customize the camera.
 * @copyright Copyright (c) 2022-23, Jacopo Maltagliati.
 * Released under the BSD 3-Clause License.
 */

#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "vec3.h"

#define ASPECT_RATIO (4.0 / 3.0)

#define IMG_WIDTH 800
#define IMG_HEIGHT 600

#define VIEWPORT_WIDTH (2.0 * ASPECT_RATIO)
#define VIEWPORT_HEIGHT 2.0

#define FOCAL_LENGTH 1.0

extern struct vec3 origin;
extern struct vec3 horizontal;
extern struct vec3 vertical;
extern struct vec3 lower_left_corner;

/**
 * @brief Initializes a viewport, calculating the lower left corner as
 * follows:
 *
 * \f$l\leftarrow O-\frac{h}{2}-\frac{v}{2}-[0,0,F]\f$
 *
 * Where:
 * - \f$h\f$ is the width vector,
 * - \f$v\f$ is the height vector,
 * - and \f$F\f$ is the focal length.
 */
void viewport_init(void);

#endif  // VIEWPORT_H
