#include "ray.h"

void ray_init(struct ray* ray, struct vec3 orig, struct vec3 dir) {
    assert(ray != NULL);
    ray->orig = orig;
    ray->dir = dir;
}

void ray_copy(struct ray* dest, const struct ray* src) {
    assert(dest != NULL);
    assert(src != NULL);
    vec3_copy(&dest->orig, src->orig);
    vec3_copy(&dest->dir, src->dir);
}

struct vec3 ray_at(const struct ray* ray, double t) {
    assert(ray != NULL);
    struct vec3 work;
    work = ray->dir;
    vec3_scale(&work, t);
    vec3_add(&work, ray->orig);
    return work;
}

/**
 * @brief Derive a color based on what the ray hits. If an object is
 * intersected, the function will return the color of said object. If no object
 * is intersected, either the color of the sky or the floor will be returned.
 *
 * @param ray
 * @return The color of the scene at the point where the ray intersects it.
 */
struct vec3 ray_color(const struct ray* ray) {
    assert(ray != NULL);
    struct object* cur = world;
    assert(world != NULL);
    double t;
    do {
        // Check if a sphere is intersected
        t = cur->hit(ray, cur->center, cur->params);
        if (t > .0) {
            struct vec3 work = ray_at(ray, t);
            vec3_unit(&work, ray->dir);
            vec3_sub(&work, cur->center);
            if (cur->flags == NORMALS) {
                vec3_add_scalar(&work, 1.0);
                vec3_scale(&work, 0.5);
                return work;
            } else {
                return cur->color;
            }
        }
        cur = cur->next;
    } while (cur != NULL);
    // Get a color based on the linear interpolation
    // of the vector's y coord (aka a vertical gradient)
    struct vec3 c1 = INIT_COLOR_WHITE;
    struct vec3 c2 = INIT_COLOR_BLUE;
    {
        struct vec3 work;
        vec3_unit(&work, ray->dir);
        t = 0.5 * (work.y + 1.0);
    }
    vec3_scale(&c1, 1.0 - t);
    vec3_scale(&c2, t);
    vec3_add(&c1, c2);
    return c1;
}

void ray_cast(struct ray* ray, int xpos, int ypos) {
    assert(ray != NULL);
    struct vec3 work;
    double v, u;
    // ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
    u = xpos / (double)(IMG_WIDTH - 1);
    v = ypos / (double)(IMG_HEIGHT - 1);
    ray->dir = lower_left_corner;
    work = horizontal;
    vec3_scale(&work, u);
    vec3_add(&ray->dir, work);
    work = vertical;
    vec3_scale(&work, v);
    vec3_add(&ray->dir, work);
    vec3_sub(&ray->dir, origin);
}
