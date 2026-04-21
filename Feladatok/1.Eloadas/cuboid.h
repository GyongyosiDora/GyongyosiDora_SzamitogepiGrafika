#ifndef CUBOID_h
#define CUBOID_H

typedef struct Cuboid {
    double a;
    double b;
    double c;
} Cuboid;

void set_size(Cuboid* cuboid, double a, double b, double c);

double calc_volume(const Cuboid* cuboid);

double calc_surface(const Cuboid* cuboid);

int has_square(const Cuboid* cuboid);

#endif