#include <stdio.h>
#include <stdlib.h>

#include "ppm.h"
#include "ray.h"
#include "vec3.h"
#include "viewport.h"
#include "object.h"

// TODO write to file
// TODO cli parameters

struct object ground = {
    .center = { .x = .0, .y = -100.5, .z = -1.0 },
    .color = INIT_COLOR_GREEN,
    .hit = &hit_sphere,
    .params[0] = 100.0,
    .flags = STANDARD,
    .next = NULL
};

struct object my_sphere = {
    .center = { .x = .0, .y = .0, .z = -1.0 },
    .color = INIT_COLOR_WHITE,
    .hit = &hit_sphere,
    .params[0] = 0.5,
    .flags = NORMALS,
    .next = &ground
};

struct object* world = &my_sphere;

int main(void) {
    struct vec3 pixel_color;
    struct ray ray;
    viewport_init();
    printf("P3\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);
    for (int j = IMG_HEIGHT - 1; j >= 0; --j) {
        for (int i = 0; i < IMG_WIDTH; ++i) {
            ray_cast(&ray, i, j);
            pixel_color = ray_color(&ray);
            write_color(&pixel_color);
        }
    }
    exit(EXIT_SUCCESS);
}
