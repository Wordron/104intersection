/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/
#include <stdlib.h>
#include <stdio.h>
#include "104_intersection.h"

int my_str_isfloat(char const *str)
{
    int i = 1;

    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0' || str[i] == '.')
            i++;
        else
            return (0);
    }
    if (str[0] == '-')
        return (1);
    if (str[0] <= '9' && str[0] >= '0')
        return (1);
    return (0);
}

int start_function(int ac, char **av)
{
    coordinate *directory_vector = malloc(sizeof(coordinate));
    coordinate *dot_start = malloc(sizeof(coordinate));
    coordinate **dot = malloc(sizeof(coordinate *) * 2);
    int nb_dot = 0;

    dot_start->x = atof(av[2]);
    dot_start->y = atof(av[3]);
    dot_start->z = atof(av[4]);

    directory_vector->x = atof(av[5]);
    directory_vector->y = atof(av[6]);
    directory_vector->z = atof(av[7]);
    for (int i = 0; i < 2; i++)
        dot[i] = malloc(sizeof(coordinate));
    if (atoi(av[1]) == 1)
        nb_dot = sphere(dot, directory_vector, dot_start, av);
    else if (atoi(av[1]) == 2)
        nb_dot = cylinder(directory_vector, dot_start, dot, av);
    else if (atoi(av[1]) == 3)
        nb_dot = cone(dot, directory_vector, dot_start, av);
    if (nb_dot == -1)
        return (84);
    display(av, nb_dot, dot);
    for (int i = 0; i < 2; i++)
        free(dot[i]);
    free(dot);
    free(dot_start);
    free(directory_vector);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 9)
        return (84);
    for (int i = 1; i < ac; i++) {
        if (my_str_isfloat(av[i]) == 0)
            return (84);
    }
    if (atof(av[5]) == 0 && atof(av[6]) == 0 && atof(av[7]) == 0)
        return (84);
    if (atof(av[1]) != 1 && atof(av[1]) != 2 && atof(av[1]) != 3)
        return (84);
    if (my_str_isfloat(av[8]) == 0)
        return (84);
    if (start_function(ac, av) == 84)
        return (84);
}