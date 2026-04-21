#include "cuboid.h"
#include <stdio.h>

int main() {
    Cuboid cuboid;

    set_size(&cuboid, 3, 4, 4);

    printf("Terfogat: %lf\n", calc_volume(&cuboid));
    printf("Felszin: %lf\n", calc_surface(&cuboid));

    if (has_square(&cuboid)) {
        printf("Van negyzet lapja\n");
    } else {
        printf("Nincs negyzet lapja\n");
    }
    return 0;
}