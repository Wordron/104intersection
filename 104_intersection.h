/*
** EPITECH PROJECT, 2022
** 104_intersection.h
** File description:
** 104_intersection
*/

#ifndef INTERSECTION_H_
    #define INTERSECTION_H_

    typedef struct coordinate
    {
        double x;
        double y;
        double z;
    } coordinate;

    int find_dot_coo(coordinate **dot, coordinate *directory_vector, coordinate *dot_start, double a, double b, double c);
    int sphere(coordinate **dot, coordinate *directory_vector, coordinate *dot_start, char **av);
    int cone(coordinate **dot, coordinate *directory_vector, coordinate *dot_start, char **av);
    int cylinder(coordinate *directory_vector, coordinate *dot_start, coordinate **dot, char **av);
    void display(char **av, int delta, coordinate **points);
    int my_str_isfloat(char const *str);

#endif /* !104_INTERSECTION_H_ */
