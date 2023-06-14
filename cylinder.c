/*
** EPITECH PROJECT, 2022
** cylinder.c
** File description:
** cylinder
*/
#include <stdlib.h>
#include <math.h>
#include "104_intersection.h"

int cylinder(coordinate *directory_vector, coordinate *dot_start, coordinate **dot, char **av)
{
    if (my_str_isfloat(av[8]) == 0 || atof(av[8]) <= 0)
        return (-1);
    double a = 0;
    double b = 0;
    double c = 0;
    int delta = 0;

    if (directory_vector->x == 0 && directory_vector->y == 0) {
        if ((pow(dot_start->x, 2) + pow(dot_start->y, 2) == pow(atof(av[8]), 2))) {
            delta = 3;
        } else
            delta = 0;
    } else {
        a = ((directory_vector->x * directory_vector->x) + (directory_vector->y * directory_vector->y));
        b = ((2 * dot_start->x * directory_vector->x) + (2 * dot_start->y * directory_vector->y));
        c = (((dot_start->x * dot_start->x)) + (dot_start->y * dot_start->y) - (atof(av[8]) * atof(av[8])));
        delta  = find_dot_coo(dot, directory_vector, dot_start, a, b, c);
    }
    return (delta);
}
