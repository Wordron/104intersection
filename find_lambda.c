/*
** EPITECH PROJECT, 2022
** find_lambda.c
** File description:
** find_lambda
*/
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "104_intersection.h"

int find_dot_coo(coordinate **dot, coordinate *directory_vector, coordinate *dot_start, double a, double b, double c)
{
    double discriminant = pow(b, 2) - (4 * a * c);
    double delta = (((b * (-1)) - sqrt(discriminant)) / (2 * a));
    double delta_two = (((b * (-1)) + sqrt(discriminant)) / (2 * a));

    if (discriminant < 0)
        return (0);
    if (round(discriminant) == 0) {
        dot[0]->x = (dot_start->x + (delta * directory_vector->x));
        dot[0]->y = (dot_start->y + (delta * directory_vector->y));
        dot[0]->z = (dot_start->z + (delta * directory_vector->z));
        dot[1] = NULL;
        return (1);
    } else if (discriminant > 0) {
        dot[0]->x = (dot_start->x + (delta_two * directory_vector->x));
        dot[0]->y = (dot_start->y + (delta_two * directory_vector->y));
        dot[0]->z = (dot_start->z + (delta_two * directory_vector->z));

        dot[1]->x = (dot_start->x + (delta * directory_vector->x));
        dot[1]->y = (dot_start->y + (delta * directory_vector->y));
        dot[1]->z = (dot_start->z + (delta * directory_vector->z));
        return (2);
    }
}
