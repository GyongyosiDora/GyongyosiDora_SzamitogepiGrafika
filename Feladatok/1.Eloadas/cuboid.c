#include "cuboid.h"
#include <math.h>

void set_size(Cuboid* cuboid, double a, double b, double c) {
    if (a > 0 && b > 0 && c > 0) {
        cuboid->a = a;
        cuboid->b = b;
        cuboid->c = c;
    } else {
        cuboid->a = cuboid->b = cuboid->c = NAN;
    }
}

double calc_volume(const Cuboid* cuboid) {
    return cuboid->a * cuboid->b * cuboid->c;
}

double calc_surface(const Cuboid* cuboid) {
    return 2 * (cuboid->a * cuboid->b + cuboid->a * cuboid->c + cuboid->b * cuboid->c);
}

int has_square(const Cuboid* cuboid) {
    if (cuboid->a == cuboid->b || cuboid->a == cuboid->c || cuboid->b == cuboid->c) {
        return 1;
    }
    return 0;
}