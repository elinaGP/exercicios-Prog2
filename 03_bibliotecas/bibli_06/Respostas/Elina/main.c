#include <stdio.h>
#include "temperature_conversor.h"

int main () {

    int num_temp=0;
    char esc_atual='0', esc_des='0';
    float temp_convertida;

    scanf ("%d %c %c", &num_temp, &esc_atual, &esc_des);

    if (esc_atual == 'c') {

        if (esc_des == 'k') {
            temp_convertida = convert_celsius_to_kelvin(num_temp);
        }
        else if (esc_des == 'f') {
            temp_convertida = convert_celsius_to_fahrenheit(num_temp);
        }
    }
    else if (esc_atual == 'k') {

        if (esc_des == 'c') {
            temp_convertida = convert_kelvin_to_celsius(num_temp);
        }
        else if (esc_des == 'f') {
            temp_convertida = convert_kelvin_to_fahrenheit(num_temp);
        }
    }
    else if (esc_atual == 'f') {

        if (esc_des == 'c') {
            temp_convertida = convert_fahrenheit_to_celsius(num_temp);
        }
        else if (esc_des == 'k') {
            temp_convertida = convert_fahrenheit_to_kelvin(num_temp);
        }
    }

    printf ("Temperature: %.2f%c", temp_convertida, esc_des - 32);
    if (esc_des != 'k') {
        printf ("º");
    }

    return 0;
}