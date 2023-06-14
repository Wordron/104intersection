#!/bin/bash


#./104intersection 3 0 1 3 3 4 5 45  ==> expect only one point
#./104intersection 3 3 4 5 3 4 5 45  ==> expect an infinity of point

make
clear

echo -e "\033[92mSimple test sphere:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e "Sphere of radius 1"
echo -e "Line passing through the point (0, 0, 2) and parallel to the vector (1, 1, 0)";
echo -e "No intersection point."
echo -e "\033[31mGot :\033[00m"
./104intersection 1 0 0 2 1 1 0 1
echo

echo -e "\033[92mSimple test sphere:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e "Sphere of radius 4"
echo -e "Line passing through the point (4, 0, 3) and parallel to the vector (0, 0, -2)";
echo -e "1 intersection point:"
echo -e "(4.000, 0.000, 0.000)"
echo -e "\033[31mGot :\033[00m"
./104intersection 1 4 0 3 0 0 -2 4
echo

echo -e "\033[92mSimple test cylinder:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e "Cylinder of radius 1"
echo -e "Line passing through the point (0, 0, 2) and parallel to the vector (1, 1, 0)";
echo -e "2 intersection points:"
echo -e "(0.707, 0.707, 2.000)"
echo -e "(-0.707, -0.707, 2.000)"
echo -e "\033[31mGot :\033[00m"
./104intersection 2 0 0 2 1 1 0 1
echo

echo -e "\033[92mSimple test cone:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e "Cone with a 30 degree angle"
echo -e "Line passing through the point (-1, -1, -1) and parallel to the vector (1, 1, 5)";
echo -e "2 intersection points:"
echo -e "(-1.568, -1.568, -3.842)"
echo -e "(-0.537, -0.537, 1.315)"
echo -e "\033[31mGot :\033[00m"
./104intersection 3 -1 -1 -1 1 1 5 30
echo

echo -e "\033[92mSimple test cylinder:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e "Cylinder of radius 1"
echo -e "Line passing through the point (1, 0, 0) and parallel to the vector (0, 0, 1)";
echo -e "There is an infinite number of intersection points."
echo -e "\033[31mGot :\033[00m"
./104intersection 2 1 0 0 0 0 1 1
echo

echo -e "\033[92mSimple test error handling:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e "84"
echo -e "\033[31mGot :\033[00m"
./104intersection 2 1 0 0 0 0 1 1 8 9
echo -e $?
echo

echo -e "\033[92mSimple test error handling:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e "84"
echo -e "\033[31mGot :\033[00m"
./104intersection 2 1 0 a 0 0 1 1
echo -e $?

echo -e "\033[92mSimple test error handling:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo -e "84"
echo -e "\033[31mGot :\033[00m"
./104intersection a 1 0 2 0 0 1 1
echo -e $?