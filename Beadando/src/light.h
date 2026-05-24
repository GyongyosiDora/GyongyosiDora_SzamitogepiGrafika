#ifndef LIGHT_H
#define LIGHT_H

#include "app.h"

typedef struct Light {
    float intensity;          // amit +/- állít
    float current_intensity; // villogó érték
    float time;              // idő a villogáshoz
} Light;

void init_light(Light* light);
void update_light(Light* light, const App* app);

#endif