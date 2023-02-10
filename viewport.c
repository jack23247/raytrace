#include "viewport.h"

struct vec3 origin = VEC3_ZERO;
struct vec3 horizontal = {.x = VIEWPORT_WIDTH, .y = 0, .z = 0};
struct vec3 vertical = {.x = 0, .y = VIEWPORT_HEIGHT, .z = 0};
struct vec3 lower_left_corner = VEC3_ZERO;

/**
 * @brief Initializes a viewport, calculating the lower left corner as follows:
 * \f$l\leftarrow O-\frac{h}{2}-\frac{v}{2}-\{0,0,F\}\f$
 * Where:
 * - h is the width vector,
 * - v is the height vector,
 * - and F is the focal length
 */
void viewport_init(void) {
    // lower_left_corner =
    //  origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
    struct vec3 work;
    lower_left_corner = origin;
    work = horizontal;
    vec3_scale(&work, 0.5);
    vec3_sub(&lower_left_corner, work);
    work = vertical;
    vec3_scale(&work, 0.5);
    vec3_sub(&lower_left_corner, work);
    vec3_init(&work, 0, 0, FOCAL_LENGTH);
    vec3_sub(&lower_left_corner, work);
}
