#include <stdio.h>
#include <math.h>

#include "vec3.h"
#include "color.h"
#include "ray.h"

#define ASPECT_RATIO (4.0 / 3.0)

#define IMG_WIDTH 800
#define IMG_HEIGHT 600

#define VIEWPORT_WIDTH 2.0 * ASPECT_RATIO
#define VIEWPORT_HEIGHT 2.0

#define FOCAL_LENGTH 1.0

// TODO write to file
// TODO cli parameters

int main(void) {

    struct vec3 origin = {.x = 0, .y = 0, .z = 0};
    struct vec3 horizontal = {.x = VIEWPORT_WIDTH, .y = 0, .z = 0};
    struct vec3 vertical = {.x = 0, .y = VIEWPORT_HEIGHT, .z = 0};
    struct vec3 lower_left_corner;

    {
        // lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
        struct vec3 midh = horizontal, midv = vertical, fl3;
        lower_left_corner = origin;
        vec3_scale(&midh, 0.5);
        vec3_scale(&midv, 0.5);
        vec3_sub(&lower_left_corner, midh);
        vec3_sub(&lower_left_corner, midv);
        vec3_init(&fl3, 0, 0, FOCAL_LENGTH);
        vec3_sub(&lower_left_corner, fl3);
    }

    printf("P3\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);

    double u, v;
    struct vec3 pixel_color;
    struct ray ray;

    for(int j = IMG_HEIGHT - 1; j >= 0; --j) {
        for(int i = 0; i < IMG_WIDTH; ++i) {
            {
                // ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
                u = i / (double)(IMG_WIDTH - 1);
                v = j / (double)(IMG_HEIGHT - 1);
                struct vec3 uh = horizontal, vv = vertical, dir = lower_left_corner;
                vec3_scale(&uh, u);
                vec3_scale(&vv, v);
                vec3_add(&dir, uh);
                vec3_add(&dir, vv);
                vec3_sub(&dir, origin);
                ray_init(&ray, origin, dir);
            }
            pixel_color = ray_color(&ray);
            write_color(&pixel_color);
        }
    }

    return 0;
}
