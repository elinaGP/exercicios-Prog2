#include "esfera_utils.h"

float calcula_volume (float R) {

    float vol=0;
    vol = (4 * PI * (R * R * R)) / 3.0;
    return vol;
}

float calcula_area (float R) {

    float area=0;
    area = 4 * PI * R * R;
    return area;
}