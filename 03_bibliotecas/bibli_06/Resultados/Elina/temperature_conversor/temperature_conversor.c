#include <stdio.h>
#include "temperature_conversor.h"

float convert_celsius_to_kelvin(float temperature) {

    float kel=0;

    kel = temperature + 273.15;
    return kel;
}

float convert_celsius_to_fahrenheit(float temperature) {

    float fah=0;

    fah = ((9.0/5.0)*temperature)+32;
    return fah;
}

float convert_kelvin_to_celsius(float temperature) {

    float cel=0;

    cel = temperature - 273.15;
    return cel;
}

float convert_kelvin_to_fahrenheit(float temperature) {

    float fah=0;

    fah = (temperature*(9.0/5.0))-459.67;
    return fah;
}

float convert_fahrenheit_to_celsius(float temperature) {

    float cel=0;

    cel = (5.0/9.0)*(temperature-32);
    return cel;
}

float convert_fahrenheit_to_kelvin(float temperature) {

    float kel=0;

    kel = (temperature+459.67)/(9.0/5.0);
    return kel;
}

float convert_temperature(float temperature, float convert_func(float temperature)) {

    return convert_func(temperature);
}