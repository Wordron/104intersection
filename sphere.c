/*
** EPITECH PROJECT, 2022
** sphere.c
** File description:
** sphere
*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "104_intersection.h"

int sphere(coordinate **dot, coordinate *directory_vector, coordinate *dot_start, char **av)
{
    if (my_str_isfloat(av[8]) == 0 || atof(av[8]) <= 0)
        return (-1);
    double a = (pow(directory_vector->x, 2) + pow(directory_vector->y, 2) + pow(directory_vector->z, 2));
    double b = ((2 * directory_vector->x * dot_start->x) + (2 * directory_vector->y * dot_start->y) + (2 * directory_vector->z * dot_start->z));
    double c = (pow(dot_start->x, 2) + pow(dot_start->y, 2) + pow(dot_start->z, 2) - pow(atof(av[8]), 2));

    return (find_dot_coo(dot, directory_vector, dot_start, a, b, c));
}
