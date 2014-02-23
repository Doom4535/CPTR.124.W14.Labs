//  File geometry.h

/*
 *  Contains the basic geometry routines for computing
 *  distance, slope, intercepts, and line equations.
 */

#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <string>

std::string print_point(double, double);

double distance(double, double, double, double);

double slope(double, double, double, double);

double intercept(double, double, double, double);

std::string line_equation(double, double);
std::string line_equation(double, double, double, double);

void intersection(double, double, double, double, double&, double&);

#endif
