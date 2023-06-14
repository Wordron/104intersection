/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display
*/
#include <stdio.h>
#include <stdlib.h>
#include "104_intersection.h"

void display(char **av, int delta, coordinate **points)
{
    if (atoi(av[1]) == 1)
        printf("Sphere of radius %s\n", av[8]);
    if (atoi(av[1]) == 2)
        printf("Cylinder of radius %s\n", av[8]);
    if (atoi(av[1]) == 3)
        printf("Cone with a %s degree angle\n", av[8]);
    printf("Line passing through the point (%s, %s, %s) and parallel to the vector (%s, %s, %s)\n", av[2], av[3], av[4], av[5], av[6], av[7]);
    if (delta == 0)
        printf("No intersection point.\n");
    if (delta == 1) {
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n", points[0]->x, points[0]->y, points[0]->z);
    }
    if (delta == 2) {
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n(%.3f, %.3f, %.3f)\n", points[0]->x, points[0]->y, points[0]->z, points[1]->x, points[1]->y, points[1]->z);
    }
    if (delta == 3)
        printf("There is an infinite number of intersection points.\n");
}
