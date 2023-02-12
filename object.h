#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>

#include "ray.h"
#include "vec3.h"

typedef struct ray ray_t;
typedef struct vec3 vec3_t;

#define STANDARD 0x01
#define NORMALS 0x02
#define GLASS 0x03

struct object {
    struct object* next;
    double (*hit)(const ray_t* r, vec3_t center, double params[]);
    double params[4];
    struct vec3 center;
    struct vec3 color;
    uint8_t flags;
};

extern struct object* scene;

// TODO allow for serializing and deserializing scenes

double hit_sphere(const ray_t* r, vec3_t center, double params[]);

#endif  // OBJECT_H
