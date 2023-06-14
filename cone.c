/*
** EPITECH PROJECT, 2022
** cone.c
** File description:
** cone
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "104_intersection.h"

int test_dot(double a, double b, double c, int delta)
{
    if (((a * pow(delta, 2)) + (b * delta) + c) == 0)
        return (1);
    return (0);
}

int test_infinit_solutions(double a, double b, double c)
{
    int dot_one = test_dot(a, b, c, 0);
    int dot_two = test_dot(a, b, c, 2);
    int dot_three = test_dot(a, b, c, 4);

    if (dot_one == 1 && dot_two == 1 && dot_three == 1)
        return (1);
    return (0);
}

void do_first_degree(coordinate **dot, coordinate *directory_vector, coordinate *dot_start, double b, double c)
{
    double delta = c / b;

    dot[0]->x = (dot_start->x + (delta * directory_vector->x));
    dot[0]->y = (dot_start->y + (delta * directory_vector->y));
    dot[0]->z = (dot_start->z + (delta * directory_vector->z));
}

int cone(coordinate **dot, coordinate *directory_vector, coordinate *dot_start, char **av)
{
    if (my_str_isfloat(av[8]) == 0)
        return (-1);
    double a = 0;
    double b = 0;
    double c = 0;
    double angle = atof(av[8]);
    int delta = 0;

    if (angle < 0 || angle >= 90)
        return (-1);
    angle = angle * (3.1415926535 / 180.0);
    a = ((pow(directory_vector->x, 2) + pow(directory_vector->y, 2)) - (pow(tan(angle), 2) * pow(directory_vector->z , 2)));
    b = (2 * ((dot_start->x * directory_vector->x) + (dot_start->y * directory_vector->y) - ((dot_start->z * directory_vector->z) * pow(tan(angle), 2))));
    c = ((pow(dot_start->x, 2) + pow(dot_start->y, 2)) - (pow(tan(angle), 2) * pow(dot_start->z, 2)));
    if (test_infinit_solutions(a, b, c) == 1)
        return (3);
    if (a <= 0.0005 && a >= -0.0005) {
        do_first_degree(dot, directory_vector, dot_start, b, c);
        delta = 1;
    } else if (a != 0)
        delta = find_dot_coo(dot, directory_vector, dot_start, a, b, c);
    return (delta);
}
