/**
 * @file main.c
 * @author Jacopo Maltagliati
 * @date 14 Feb 2023
 * @brief Entry point for the raytracer.
 * @copyright Copyright (c) 2022-23, Jacopo Maltagliati.
 * Released under the BSD 3-Clause License.
 */

#include <stdio.h>
#include <stdlib.h>

#include "ppm.h"
#include "ray.h"
#include "viewport.h"

// TODO write to file
// TODO cli parameters

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
